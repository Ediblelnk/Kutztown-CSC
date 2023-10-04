; 
; Find first 25 Fibonacci numbers
; print them in reverse order
; 
; Name: Peter Schaefer

include Irvine32.inc

.data
NUM = 25
fibs DWORD 2 DUP(1), NUM-2 DUP(?)	; NUM number of dwords

.code
main PROC
	mov ecx, NUM - 2					; prepare the loop, two less
	mov esi, OFFSET fibs + TYPE fibs	; already set a fib num

FIB_FILL:
	mov eax, [esi - TYPE fibs]		; value of second prior number
	add esi, TYPE fibs				; increment to next place
	add eax, [esi - TYPE fibs]		; value of first prior number
	mov [esi], eax					; set value of next fib number
	loop FIB_FILL

FIB_CLEAN:
	mov ecx, NUM		; reset loop counter

FIB_PRINT:
	mov eax, [esi]		; load value of last fib number
	call WriteDec		; write to output
	call Crlf			; newline
	sub esi, TYPE fibs	; go to previous fib number
	loop FIB_PRINT

ENDING:
	call WaitMsg
	invoke ExitProcess,0

main ENDP
END main