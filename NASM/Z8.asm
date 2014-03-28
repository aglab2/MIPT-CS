global main		 

SECTION .bss
	a resb 1

SECTION .text		
main:				
	mov		eax, 3
	mov		ebx, 0
	mov		ecx, a
	mov		edx, 1
	int		0x80
	
	mov		eax, [a]
	or		eax, 7
	mov		[a], eax
	
	mov		edx,1		
	mov		ecx,a		
	mov		ebx,1		
	mov		eax,4		
	int		0x80	

	mov	ebx,0		
	mov	eax,1		
	int	0x80		
