; 
; Count matching vowels in a string
; 
; Name:
;
include Irvine32.inc

.data
vowels BYTE "tsu"
vowels_len = ($ - vowels)
vowel_counts BYTE vowels_len DUP(0)

prompt BYTE "Enter a string: ",0
separator BYTE ": ",0

string_len = 100

.data?
string BYTE string_len+1 DUP(?)

.code
main PROC

; prompt the user for a user input string
	mov edx, OFFSET prompt
	call WriteString

; read and store a user input string
	mov edx, OFFSET string
	mov ecx, string_len
	call ReadString

; loop and call CountChars on each vowel
	mov ecx, vowels_len
	mov esi, OFFSET vowels
COUNT:
	mov al, BYTE PTR [esi]			; eax holds the test character
	mov ebx, OFFSET string			; ebx holds the string

	call CountChars
	mov BYTE PTR [esi+vowels_len], dl

	inc esi
	loop COUNT

; print out all the characters and their corresponding amounts
	mov ecx, vowels_len
	mov esi, OFFSET vowels
PRINT:
	mov al, BYTE PTR [esi]
	call WriteChar

	mov edx, OFFSET separator
	call WriteString

	movzx eax, BYTE PTR [esi+vowels_len]
	call WriteDec

	call Crlf

	inc esi
	loop PRINT

; wait and cleanup
	call WaitMsg					; wait for user to hit enter
	invoke ExitProcess,0		
main ENDP

CountChars PROC
; Descrption:
;	Calculates and returns the amount a character is contained in a string
; Receives:
;	EAX = the character searched for
;	EBX = memory address of the beginning of string
; Returns:
;	EDX = the number of times the character occured in the string
; Requires:
;	EBX string MUST be null-terminated

	mov edx, 0
NEXT_CHAR:
	cmp al, BYTE PTR [ebx]
	jnz NO_MATCH
	inc edx	; only increments the count if they do match
NO_MATCH:
	inc ebx
	cmp BYTE PTR [ebx], 0
	jnz NEXT_CHAR

	ret
CountChars ENDP

END main