; 
; fib5 - generate Fibonnaci numbers
; 

include Irvine32.inc

.code

main PROC
	mov eax,1
	mov ebx,1
	add eax,ebx
	add ebx,eax
	add eax,ebx
	invoke ExitProcess,0	; 'bye
main ENDP

END main