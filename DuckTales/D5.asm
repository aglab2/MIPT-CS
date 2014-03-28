global main

extern scanf
extern printf
extern exit
extern leap

SECTION .data
	fin  : db "%d", 0
	
	AC	 : db "Key accepted.", 0xa, 0
	NO	 : db "Wrong key!", 0xa, 0
	
	int1 : times 4 db 0
	
SECTION .text
main:
	fld		fpi
	push	int1
	push	fin 
	call	scanf

	mov		eax, int1
	push	eax
	call	leap
	
	test	eax, eax
	jz 		L1
	
	push	AC
	call	printf
L1:	push	0
	call	exit

