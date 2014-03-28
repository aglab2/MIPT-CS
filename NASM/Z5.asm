global main

extern scanf
extern printf
extern exit

SECTION .data
	fin	 : db "%d", 0
	fout1: db "%d", 0xa, 0
	
	int1 : times 4 db 0
	int2 : times 4 db 0
	int3 : times 4 db 0

SECTION .text
main:
	push 	int1
	push 	fin 
	call 	scanf
	add		esp, 8

	push 	int2
	push 	fin 
	call 	scanf
	add		esp, 8

	xor 	eax, eax
	xor 	ebx, ebx
	xor		ecx, ecx
	xor		edx, edx

	mov		edi, [int1]
	mov		esi, [int2]

	cmp 	edi, esi
	jg		Cycle
	mov		esi, [int1]
	mov		edi, [int2]

Cycle:
	add		ecx, esi
	mov		eax, ecx
	cdq		
	idiv	edi
	test	edx, edx
	jnz		Cycle		
		
	push	ecx
	push	fout1
	call	printf
	add		esp, 8
	push	0
	call	exit
