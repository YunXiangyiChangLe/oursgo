

global _start
extern myprint

_start:
	push	ebp
	push 	 ebp 	 , 	 esp
	mov 	 eax 	 , 	 1
	push	eax
	add 	 eax 	 , 	 1
	mov 	 ebx 	 , 	 eax
	push	ebx
	add 	 ebx 	 , 	 1
	mov 	 ecx 	 , 	 ebx
	push	ecx
	add 	 ecx 	 , 	 1
	mov 	 esx 	 , 	 ecx
	push	esx
	add 	 esx 	 , 	 1
	mov 	 esi 	 , 	 esx
	push	esi
	add 	 esi 	 , 	 1
	mov 	 eax 	 , 	 esi
	push	eax
	add 	 eax 	 , 	 1
	mov 	 eax 	 , 	 eax
	push	eax
	add 	 eax 	 , 	 1
	mov 	 eax 	 , 	 eax
	pop	ebp
	mov 	 eax 	 , 	 1
	mov 	 ebx 	 , 	 0
	int	80h


