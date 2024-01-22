; 
; Load a list of olympians into an array of structs
; print them out, calculating the olympian's total medals
;
; Name: PETER SCHAEFER
; 

include Irvine32.inc

;;;; define some constants
FSIZE = 150				; max file name size
CR = 0Dh				; c/r
LF = 0Ah				; line feed
ASTERISK = 2Ah			; asterisk for new entry
NULL = 00h				; null character
SPACE = 20h				; space character
STRSIZE = 32			; string sizes in struct
NUMTESTS = 3			; number of olympian medals
ROUND = 1				; cutoff for rounding

MEDAL TYPEDEF DWORD		; just in case you don't want a medal to be a DWORD

olympian STRUCT
	sname BYTE STRSIZE DUP('n')		; 32 bytes	
	country BYTE STRSIZE DUP('c')	; 32
	medals MEDAL NUMTESTS DUP(0)	; NUMTESTS x 4
olympian ENDS						; 76 total

.data
filename BYTE FSIZE DUP(?)							; array to hold the file name
filehandle DWORD 0									; the file handle
prompt1 BYTE "Enter the number of olympians: ",0	; prompt for a string
prompt2 BYTE "Enter a filename: ",0					; prompt for a string
ferror BYTE "Invalid input...",0					; error message
perror BYTE "Fatal program error...",0				; internal error

maxnum DWORD 0		; max number of olympians
slistptr DWORD 0	; pointer to olympian list
numread	DWORD 0		; number of olympians loaded

;;;; for output listing (these can be used as globals)
outname  BYTE "Olympian: ",0
outcountry BYTE "Country: ",0
outmedals  BYTE "Medals: ",0

.code
main PROC
REPROMPT_NUM:
	;;;; prompt for the number of olympians
    mov edx, OFFSET prompt1			; output the prompt
	call WriteString				; uses edx 
	call ReadInt					; get the maximium number of olympians
	jno ACCEPT_NUM
	mov edx, OFFSET ferror
	call WriteString
	call Crlf						; newline
	jmp REPROMPT_NUM

ACCEPT_NUM:
	mov maxnum, eax					; save it

	;;;; access the heap and allocate memory for olympian struct array
	push maxnum						; push value as argument of allocOlympians
	call allocOlympians
	jc ERROR						; end the program if unable to allocate
	mov slistptr, eax				; store a pointer to the heap data

REPROMPT_FILE:
	;;;; prompt for the file name 
    mov edx, OFFSET prompt2			; output the prompt
	call WriteString				; uses edx 

	;;;; read the file name
	mov edx, OFFSET filename		; point to the start of the file name string
	mov ecx, FSIZE				    ; max size for file name
	call ReadString					; load the file name (string pointer in edx, max size in ecx)
	
	;;;; open the file, get the file pointer
	mov edx, OFFSET filename		
	call OpenInputFile

	cmp eax, INVALID_HANDLE_VALUE
	jne ACCEPT_FILE					; has an error occured opening the file?
	mov edx, OFFSET ferror
	call WriteString
	call Crlf
	jmp REPROMPT_FILE

ACCEPT_FILE:
	mov filehandle, eax				; store the file pointer

	;;;; load the olympian information
	push slistptr					; push arguments to loadALLOlympians
	push filehandle
	push maxnum
	call loadAllOlympians

	;;;; output the olympian information
	push slistptr
	push eax						; eax holds the number of olympians read
	call outputAllOlympians

	;;;; close the file
	push filehandle
	call CloseHandle
	jmp DONE

ERROR:
	mov edx, OFFSET perror			; something went horribly wrong
	call WriteString
	call Crlf

DONE:
	call WaitMsg					; wait for user to hit enter
	invoke ExitProcess,0			; bye
main ENDP

; description:
;	read a character from a file
; receives (in reverse order):
readFileChar PROC
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

; description:
;	allocates sufficient memory from to store the inputted number of olypian structs
; receives (in reverse order):
allocOlympians PROC,
	ssize: DWORD	; the number of structs in the array
; returns:
;	eax = a pointer to the allocated array, or carry flag if error

	mov eax, ssize
	imul eax, SIZEOF OLYMPIAN	; calculate number of bytes needed to allocate
	jz ERROR
	mov ssize, eax
	
	call GetProcessHeap			; get a handle to this process heap in EAX
	push ssize					; requested size of allocation
	push HEAP_ZERO_MEMORY		; zero out all data in the allocation
	push eax					; handle to process heap
	call HeapAlloc
	cmp eax, 0					; NULL pointer?
	je ERROR
	jmp DONE

ERROR:
	stc							; return with CF = 0

DONE:
	ret
allocOlympians ENDP

; description:
;	reads a line from the specified filepointer/filehandle, 
;	and puts it into stringpointer buffer, up to stringsize characters
; receives (in reverse order):
readFileLine PROC uses EBX ESI,
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

	dec stringsize				; there is one less byte available in the buffer
	jz NULL_TERMINATE			; terminate string and leave

	cmp al, LF					; if the loaded character was a line fead, null terminate
	jz NULL_TERMINATE

	inc ebx						; increment the characters read
	mov BYTE PTR [esi], al		; store the character in string array
	inc esi						; point to next position in string array
	jmp NEXT_CHAR

NULL_TERMINATE:
	mov BYTE PTR [esi], NULL	; null terminate the string
	jmp DONE

ERROR:
	stc

DONE:
	pop stringpointer
	pop stringsize				; restore the arguments previously saved

	mov eax, ebx				; eax returns the number of characters read/stored
	ret
readFileLine ENDP

; description:	
;	reads information from a file and loads it into an olympian struct.
; recieves (in reverse order):
loadOlympian PROC uses ESI EDI ECX EDX,
	filepointer: DWORD,			; the pointer to the file read from
	structpointer: DWORD		; the pointer to the memory to write the struct
	local stringbuffer[STRSIZE]: BYTE
; returns:
;	eax = updated file pointer, which has been advanced past the information just loaded
; error:
;	carry = set
	
	mov esi, [structpointer]	; esi points to the struct on the heap

	push filepointer			; push arguments to readFileline
	lea edi, stringbuffer
	push edi					; loads local string for checking if properly formatted
	push STRSIZE
	call readFileLine
	jc ERROR
	cmp stringbuffer, ASTERISK	; properly formatted has '*' at beginning
	jnz ERROR

	push filepointer			; load the name
	push esi
	push STRSIZE
	call readFileLine
	jc ERROR

	add esi, SIZEOF OLYMPIAN.sname

	push filepointer			; load the country
	push esi
	push STRSIZE
	call readFileLine
	jc ERROR

	add esi, SIZEOF OLYMPIAN.country

	mov ecx, NUMTESTS			; repeat for the number of medals
LOAD_MEDAL:
	push filepointer			; load goal medals INTO buffer
	push edi
	push STRSIZE
	call readFileLine
	jc ERROR

	push ecx					; store loop counter
	mov ecx, eax				; move the number of characters read into ecx
	mov edx, edi				; store pointer to stringbuffer in edx
	call ParseInteger32
	jo ERROR					; if parsing error, exit

	mov [esi], eax				; write medal amount to struct
	add esi, SIZEOF MEDAL		; increment to next medal
	pop ecx						; restore loop counter
	loop LOAD_MEDAL
	jmp DONE

ERROR:
	stc

DONE:
	mov eax, filepointer
	ret
loadOlympian ENDP

; description:
;	makes successive calls to loadOlympian to read olympian information from a 
;	file into an array of olympian structs
; receives (in reverse order):
loadAllOlympians PROC uses ESI ECX EBX,
	maxOlympians: DWORD,		; the max olympians to be read
	filepointer: DWORD,			; pointer to the file
	structpointer: DWORD		; pointer to struct on the heap
; returns:
;	eax = number of olympians actually read

	mov ebx, 0					; zero olympians have been read initially
	mov esi, structpointer		;
	mov ecx, maxOlympians		; prepare loop
LOAD_OLYMPIAN:
	push esi					; push pointer to current place of struct array
	push filepointer
	call loadOlympian
	jc ERROR
	inc ebx						; one more olympian has been read
	add esi, SIZEOF OLYMPIAN	; increment to next olympian in array
	loop LOAD_OLYMPIAN

ERROR:
	mov eax, ebx				; return number of olympians read in eax
	ret

loadAllOlympians ENDP

; description:
;	Outputs the contents of one olympian struct to the console in a 
;	well formatted manner.
; receives (in reverse order):
outputOlympian PROC uses ESI EDX ECX EAX,
	structpointer: DWORD,		; pointer to the struct
; returns:
;	there is no return value for this proc

	mov esi, structpointer				; esi holds a pointer to beginning of struct

	mov edx, OFFSET outname				; output the olympians name
	call WriteString
	mov edx, esi
	call WriteString
	call Crlf
	add esi, SIZEOF OLYMPIAN.sname		; move pointer to country

	mov edx, OFFSET outcountry			; output the olympians country
	call WriteString
	mov edx, esi
	call WriteString
	call Crlf
	add esi, SIZEOF OLYMPIAN.country	; move pointer to gold medals
	
	mov ecx, NUMTESTS
	mov eax, 0							; ebx holds the sum of the medals
SUM_MEDAL:
	add eax, MEDAL PTR [esi]
	add esi, SIZEOF MEDAL
	loop SUM_MEDAL

	mov edx, OFFSET outmedals
	call WriteString
	call WriteDec						; writes sum of medals
	call Crlf
	
	ret
outputOlympian ENDP

; description:
;	output the entire array of Olympians to the console by successively
;	calling outputOlympian
; receives (in reverse order):
outputAllOlympians PROC uses ESI,
	maxOlympians: DWORD,		; number of olympians to output
	structpointer: DWORD,		; pointer to array of olympians
; returns:
;	there is no return value for this proc
	
	mov esi, structpointer		; esi points to the struct on the heap

	call Crlf
	mov ecx, maxOlympians		; repeat for requested olympians
OUTPUT_OLYMPIAN:
	push esi
	call outputOlympian			; output an olympian
	add esi, SIZEOF OLYMPIAN	; move to next olympian
	call Crlf
	loop OUTPUT_OLYMPIAN

	ret
outputAllOlympians ENDP

END main
