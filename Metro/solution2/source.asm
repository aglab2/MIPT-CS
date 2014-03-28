global main

extern printf
extern exit

SECTION .data
	fout: db "%d", 0xa, 0

SECTION .text
main:
	mov	eax, [0x4+esp]
	dec	eax

	push	eax
	call	exit
