

global _start
extern myprint

_start:
	push	ebp
	mov 	 ebp 	 , 	 esp
	mov 	 eax 	 , 	 1
	mov 	 ebx 	 , 	 2
	sub 	 esp 	 , 	 4
	push	eax
	call	myprint
	add 	 esp 	 , 	 0
	pop	ebp
	mov 	 eax 	 , 	 1
	mov 	 ebx 	 , 	 0
	int	80h


