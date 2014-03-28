global main

extern printf
extern exit

SECTION .data
	fout: db "%d", 0xa, 0

SECTION .text
main:
	pop		edx
	dec		edx
	push	edx
	push	fout
	call	printf
	
	push	0
	call	exit
