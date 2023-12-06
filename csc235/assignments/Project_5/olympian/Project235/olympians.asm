; 
; Load a list of olympians into an array of structs
; print them out, calculating the olympian's total medals
;
; Name:
; 

include Irvine32.inc

; define some constants
FSIZE = 150							; max file name size
CR = 0Dh							; c/r
LF = 0Ah							; line feed
ASTERISK = 2Ah						; asterisk for new entry
NULL = 00h							; null character
SPACE = 20h							; space character
STRSIZE = 32						; string sizes in struct
NUMTESTS = 3						; number of olympian medals
ROUND = 1							; cutoff for rounding

olympian STRUCT
	sname BYTE STRSIZE DUP('n')		; 32 bytes	
	country BYTE STRSIZE DUP('c')	; 32
	medals DWORD NUMTESTS DUP(0)	; NUMTESTS x 4
olympian ENDS						; 76 total

.data
filename BYTE FSIZE DUP(?)			; array to hold the file name
filehandle DWORD 0					; the file handle
loadstring BYTE FSIZE DUP(1)		; string buffer to load from file
prompt1 BYTE "Enter the number of olympians: ",0	; prompt for a string
prompt2 BYTE "Enter a filename: ",0	; prompt for a string
ferror BYTE "Invalid input...",0	; error message

maxnum DWORD 0						; max number of olympians
slistptr DWORD 0					; pointer to olympian list
numread	DWORD 0						; number of olympians loaded

; for output listing (these can be used as globals)
outname  BYTE "Olympian: ",0
outcountry BYTE "Country: ",0
outmedals  BYTE "Medals: ",0

.code
main PROC
	; prompt for the number of olympians 
    mov edx,OFFSET prompt1			; output the prompt
	call WriteString				; uses edx 
	call ReadInt					; get the maximium number of olympians
	mov maxnum, eax					; save it

	;;;;;;;;;;;;;;;;;;;
	; access the heap and allocate memory for olympian struct array
	;;;;;;;;;;;;;;;;;;

	mov eax, maxnum					;
	imul eax, SIZEOF olympian		; calculate number of bytes needed to allocate
	push eax						; push value as argument of allocOlympians
	call allocOlympians
	jc ERROR						; end the program if unable to allocate

	; prompt for the file name 
    mov edx,OFFSET prompt2			; output the prompt
	call WriteString				; uses edx 

	; read the file name
	mov edx, OFFSET filename		; point to the start of the file name string
	mov ecx, FSIZE				    ; max size for file name
	call ReadString					; load the file name (string pointer in edx, max size in ecx)
	
	;;;;;;;;;;;;;;;;;;
	; open the file, get the file pointer
	;;;;;;;;;;;;;;;;;;
	mov edx, OFFSET filename		
	call OpenInputFile

	cmp eax, INVALID_HANDLE_VALUE
	je ERROR						; an error has occured with opening the file

	mov filehandle, eax				; store the file pointer

L1:
	push filehandle					; pointer to the file
	push OFFSET loadstring			; pointer to the string buffer
	push FSIZE						; need to leave room for NULL terminator
	call readFileLine				;
	jmp L1


	;;;;;;;;;;;;;;;;;;
	; load the olympian information
	;;;;;;;;;;;;;;;;;;

	;;;;;;;;;;;;;;;;;;
	; output the olympian information
	;;;;;;;;;;;;;;;;;;

	;;;;;;;;;;;;;;;;;;
	; be sure to:
	;     close the file
	;     handle any errors encountered
	;;;;;;;;;;;;;;;;;;

ERROR:

DONE:
	call WaitMsg					; wait for user to hit enter
	invoke ExitProcess,0			; bye
main ENDP

readFileChar PROC
; description:
;	read a character from a file
; receives (in reverse order):
;	[ebp+8]  = file pointer
; returns:
;	eax = character read, or system error code if carry flag is set

	push ebp						; save the base pointer
	mov ebp,esp						; base of the stack frame
	sub esp,4						; create a local variable for the return value
	push edx						; save the registers
	push ecx

	mov eax,[ebp+8]					; file pointer
	lea edx,[ebp-4]					; pointer to value read
	mov ecx,1						; number of chars to read
	call ReadFromFile				; gets file handle from eax (loaded above)
	jc DONE							; if CF is set, leave the error code in eax
	mov eax,[ebp-4]					; otherwise, copy the char read from local variable

DONE:
	pop ecx							; restore the registers
	pop edx
	mov esp,ebp						; remove local var from stack 
	pop ebp
	ret 4
readFileChar ENDP

; descriptions:
;	allocates sufficient memory from to store the inputted number of olypian structs
; receives (in reverse order):
allocOlympians PROC,
	ssize: DWORD	; the number of structs in the array
; returns:
;	eax = a pointer to the allocated array, or carry flag if error

	call GetProcessHeap		; get a handle to this process heap in EAX
	push ssize				; requested size of allocation
	push HEAP_ZERO_MEMORY	; zero out all data in the allocation
	push eax				; handle to process heap
	call HeapAlloc

	cmp eax, 0				; pointer to memory
	jne OK					; zero on failure
	stc
	jmp DONE

OK:
	clc						; return with CF = 0

DONE:
	ret
allocOlympians ENDP

; description:
;	reads a line from the specified filepointer/filehandle, 
;	and puts it into stringpointer buffer, up to stringsize characters
; receives (in reverse order):
readFileLine PROC uses EBX,
	stringsize: DWORD,		; maximum size of the buffer
	stringpointer: DWORD,	; pointer to the string buffer
	filepointer: DWORD,		; pointer to the filehandle
; returns:
;	eax = the number of characters read and stored in the target array

	push stringsize				; save the arguments to restore later
	push stringpointer

	mov ebx, 0					; EBX will hold count of characters loaded
	mov esi, stringpointer		; load the address of the string buffer

NEXT_CHAR:
	push filepointer
	call readFileChar			; load a character
	jc ERROR

	cmp al, CR					; if the loaded character was a carriage return, ignore
	jz NEXT_CHAR

	inc ebx
	dec stringsize				; there is one less byte available in the buffer
	jz NULL_TERMINATE			; terminate string and leave

	cmp al, LF					; if the loaded character was a line fead, null terminate
	jz NULL_TERMINATE

	mov BYTE PTR [esi], al		; store the character in string array
	inc esi						; point to next position in string array
	jmp NEXT_CHAR

NULL_TERMINATE:
	mov BYTE PTR [esi], 0		; null terminate the string
	jmp DONE

ERROR:
	stc

DONE:
	pop stringpointer
	pop stringsize				; restore the arguments previously saved

	mov eax, ebx				; eax returns the number of characters read/stored
	ret
readFileLine ENDP

END main
