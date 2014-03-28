global main

extern scanf
extern printf
extern exit

SECTION .data
	fin : db "%d", 0
	int : times 4 db 0
	
SECTION .text
main:
	push	int
	push	fin 
	call	scanf
	add		esp, 8
