

global _start
extern myprint

_start:
	push	ebp
	mov 	 ebp 	 , 	 esp
	mov 	 eax 	 , 	 1
	push	eax
	add 	 eax 	 , 	 1
	mov 	 ebx 	 , 	 eax
	push	ebx
	add 	 ebx 	 , 	 1
	mov 	 ecx 	 , 	 ebx
	push	ecx
	add 	 ecx 	 , 	 1
	mov 	 edx 	 , 	 ecx
	push	edx
	add 	 edx 	 , 	 1
	mov 	 esi 	 , 	 edx
	push	esi
	add 	 esi 	 , 	 1
	mov 	 eax 	 , 	 esi
	push	eax
	add 	 eax 	 , 	 1
	mov 	 eax 	 , 	 eax
	push	eax
	add 	 eax 	 , 	 1
	mov 	 eax 	 , 	 eax
	sub 	 esp 	 , 	 4
	mov 	 edi 	 , 	 [ ebp - 4 ]
	push	edi
	call	myprint
	add 	 esp 	 , 	 0
	sub 	 esp 	 , 	 4
	mov 	 edi 	 , 	 [ ebp - 8 ]
	push	edi
	call	myprint
	add 	 esp 	 , 	 0
	sub 	 esp 	 , 	 4
	mov 	 edi 	 , 	 [ ebp - 12 ]
	push	edi
	call	myprint
	add 	 esp 	 , 	 0
	pop	ebp
	mov 	 eax 	 , 	 1
	mov 	 ebx 	 , 	 0
	int	80h


