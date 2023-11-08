; 
; Count matching vowels in a string
; 
; Name: Peter Schaefer
;
include Irvine32.inc

.data
; vowel variables
vowels BYTE "aeiou"
vowels_len = ($ - vowels)
vowel_counts BYTE vowels_len DUP(0)

; string variables / prompts
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
	mov ecx, vowels_len					; set up loop amount
	mov esi, OFFSET vowels				; point ESI at beginning of vowel array
COUNT:
	mov al, BYTE PTR [esi]				; eax holds the test character
	mov ebx, OFFSET string				; ebx holds the string
	call CountChars					
	mov BYTE PTR [esi+vowels_len], dl	; move result from CountChars into num array

	inc esi								; increment to next test character and loop
	loop COUNT

; print out all the characters and their corresponding amounts
	mov ecx, vowels_len						; set up loop amount
	mov esi, OFFSET vowels					; point ESI at beginning of vowel array
PRINT:
	mov al, BYTE PTR [esi]					; eax holds character to write
	call WriteChar

	mov edx, OFFSET separator				; edx holds string to write
	call WriteString

	movzx eax, BYTE PTR [esi+vowels_len]	; move count of vowel into eax
	call WriteDec
	call Crlf

	inc esi									; move to next character
	loop PRINT

; wait and cleanup
	call WaitMsg
	invoke ExitProcess,0
main ENDP

CountChars PROC USES eax ebx
; Descrption:
;	Calculates and returns the amount a character is contained in a string
; Receives:
;	EAX = the character searched for, stored in AL
;	EBX = memory address of the beginning of string
; Returns:
;	EDX = the number of times the character occured in the string
; Requires:
;	EBX string MUST be null-terminated

	mov edx, 0				; edx will return the final count so start with 0
NEXT_CHAR:
	cmp al, BYTE PTR [ebx]	; does the current character match the test character?
	jnz NO_MATCH			; no match, skip over count increment
	inc edx					; only increments the count if they do match
NO_MATCH:
	inc ebx					; move to the next character
	cmp BYTE PTR [ebx], 0	; is the next charater the null temrinator?
	jnz NEXT_CHAR			; not null terminator, continue

	ret						; was the null terminator, return
CountChars ENDP

END main