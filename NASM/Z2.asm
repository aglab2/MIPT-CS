global main

extern scanf
extern printf
extern exit

SECTION .data
fin:	db "%d", 0
fout1:	db "%d", 0xA, 0
fout2:  db :"%d", 0xA, 0
int1 : 	times 4 db 0
int2 : 	times 4 db 0
int3 : 	times 4 db 0
	
SECTION .text
main:
	push 	int1
	push 	fin 
	call 	scanf
	add	esp, 8

	push 	int2
	push 	fin 
	call 	scanf
	add	esp, 8
	
	xor 	eax, eax
	add	eax, [int1]
	sub	eax, [int2]
	
	push	eax
	push	fout1
	call	printf
	add	esp, 8
	push	0
	call	exit
