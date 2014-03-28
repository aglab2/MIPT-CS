global main

extern puts
extern exit

SECTION .data
	msg  :		db "Liberté, égalité, fraternité!",0xA,0

SECTION .text
main:
	push 	dword msg
	call 	puts
	sub 	esp, 4
		
	push dword 0
	call exit
