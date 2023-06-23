global _start
extern myprint

_start:
	push	ebp
	mov	ebp,	esp

	mov	eax,	1
	mov	ebx,	0
	int	80h
