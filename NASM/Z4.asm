global main

extern scanf
extern printf
extern exit

SECTION .data
	fin	 : db "%d", 0
	
	fout : db "%d %d", 0xa, 0
	fout1: db "YES", 0xa, 0
	fout2: db "NO", 0xa, 0
	
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
	
	mov 	eax, 0x7FFFFFFF
	sub		eax, [int1]
	mov		ebx, [int2]
	
	;push	ebx
	;push 	eax
	;push	fout
	;call	printf
	;add	esp, 12
	
	cmp 	eax, ebx
	jg		else	
	push	fout1
	jmp 	if
else:		
	push	fout2
if:
	call	printf
	add		esp, 4
	
	push	0
	call	exit
