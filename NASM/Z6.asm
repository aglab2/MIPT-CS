global main

extern scanf
extern printf
extern exit

SECTION .data
	fin	 : db "%d", 0
	fout1: db "%d ", 0
	
	int1 : times 4 db 0
	int2 : times 4 db 0

SECTION .bss
	a resd 40004

SECTION .text
main:
	push 	int1
	push 	fin 
	call 	scanf
	add		esp, 8

	xor 	eax, eax
	xor 	ebx, ebx
	xor		ecx, ecx
	xor		edx, edx
	xor		edi, edi
	
	mov		esi, [int1]
Cycle:
	push 	int2
	push 	fin 
	call 	scanf
	add		esp, 8
	
	mov		ebx, [int2]
	lea		ecx, [a+edi]
	mov		[ecx], ebx
	
	add		edi, 4
	dec		esi
	
	jnz		Cycle
	
	mov		esi, [int1]
	lea		edx, [-4+a]
	
Cycle2:
	call	Finder
	mov		ebx, [edx+esi*4]
	
	push 	edx
	push	ebx
	push	fout1
	call	printf
	add		esp, 8
	pop 	edx
	
	
	dec		esi
	jnz		Cycle2
	
	push	0
	call	exit



Finder:
	lea		ebx, [edx+4]
	lea		edi, [esi]
Cycle3:
	mov		eax, [edx+edi*4]
	cmp		[ebx], eax
	
	jl		Rev
	lea		ebx, [edx+edi*4]
Rev:
	dec		edi
	;cmp 	edi, 1
	jnz		Cycle3
	
	mov		edi, [edx+esi*4]
	mov		eax, [ebx]
	mov		[ebx], edi
	mov		[edx+esi*4], eax
ret
