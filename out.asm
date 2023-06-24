

global _start
extern myprint

add1:
	push	ebp
	mov 	 ebp 	 , 	 esp
	push	eax
	push	ebx
	push	ecx
	push	edx
	push	esi
