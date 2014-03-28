global main

extern scanf
extern printf
extern exit

SECTION .data
	fin  : db "%d", 0
	
	AC	 : db "Key accepted.", 0xa, 0
	NO	 : db "Wrong key!", 0xa, 0
	
	int1 : times 4 db 0
	int2 : times 4 db 0
	
SECTION .text
main:
	push	int1
	push	fin 
	call	scanf

	push	int2
	push	fin 
	call	scanf

	mov		eax, int1
	mov		ebx, int2
	sub		eax, ebx
	cmp		eax,0x18894
	je		wc
	
	push	AC
	call	printf
	push	0
	call	exit
	
wc:
	push	NO
	call	printf
	jmp		main
	nop
