global main
extern exit

SECTION .data
	a: dd 1000000000

SECTION .text
main:
	push	a
	push	0
	call	exit
