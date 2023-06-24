

global _start
extern myprint

_start:
	push	ebp
	mov 	 ebp 	 , 	 esp
	mov 	 eax 	 , 	 0
	mov 	 ebx 	 , 	 0
	cmp 	 ebx 	 , 	 10
	jg	ENDFOR0
	FORLOOP0:
	push	eax
	add 	 eax 	 , 	 ebx
	mov 	 [ ebp - 4 ] 	 , 	 eax
	sub 	 esp 	 , 	 4
	push	eax
	call	myprint
	add 	 esp 	 , 	 0
	push	ebx
	add 	 ebx 	 , 	 1
	mov 	 [ ebp - 16 ] 	 , 	 ebx
	cmp 	 ebx 	 , 	 10
	jle	FORLOOP0
	ENDFOR0:
	pop	ebp
	mov 	 eax 	 , 	 1
	mov 	 ebx 	 , 	 0
	int	80h


