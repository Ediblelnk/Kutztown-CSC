; Reversing a String (RevStr.asm)
; This program reverses a string. (modified JAC)

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
aName byte "Abraham Lincoln",0
nameSize = ($ - aName) - 1	; skip the NULL

.code
main proc
	mov	 ecx,nameSize		; set up loop over characters
	mov	 esi,OFFSET aName	; esi is index into array

L1:	movzx ax, BYTE PTR [esi]	; get character
	push ax				; push a character onto stack
	add esi, TYPE BYTE
	loop L1

	; Pop the name from the stack in reverse
	; and store it in the aName array.

	mov	 ecx,nameSize
	mov	 esi,0

L2:	pop  ax				; get character
	mov	 aName[esi],al		; store in string
	inc	 esi
	loop L2

	Invoke ExitProcess,0
main endp
end main