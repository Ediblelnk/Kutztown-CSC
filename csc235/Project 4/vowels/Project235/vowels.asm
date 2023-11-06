; 
; Count matching vowels in a string
; 
; Name:
;
include Irvine32.inc

.data
vowels BYTE "aeiou",0
vowel_counts BYTE 5 DUP(0)

.data?
string BYTE 101 DUP(?)

.code
main PROC

	mov edx, OFFSET string
	mov ecx, 100
	call ReadString
	call WaitMsg					; wait for user to hit enter
	invoke ExitProcess,0			; bye
main ENDP

; CountChars procedure

END main