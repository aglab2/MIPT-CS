global main

extern scanf
extern printf
extern exit

SECTION .data
    message1: db "Enter the first number: ", 0
    message2: db "Enter the second number: ", 0
    formatin: db "%d", 0
    formatout: db "%d", 10, 0 ; newline, nul terminator
    integer1: times 4 db 0 ; 32-bits integer = 4 bytes
    integer2: times 4 db 0 ;
SECTION .text
   global _main 
   extern _scanf 
   extern _printf     

main:

   push ebx ; save registers
   push ecx
   push message1
   call printf

   add esp, 4 ; remove parameters
   push integer1 ; address of integer1 (second parameter)
   push formatin ; arguments are right to left (first parameter)
   call scanf

   add esp, 8 ; remove parameters
   push message2
   call printf

   add esp, 4 ; remove parameters
   push integer2 ; address of integer2
   push formatin ; arguments are right to left
   call scanf

   add esp, 8 ; remove parameters
	push dword 0
	call exit
