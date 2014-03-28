global main

extern scanf
extern printf
extern exit

SECTION .data
	fin	 : db "%f%f", 0
	fout : db "%f", 0xa, 0

SECTION .text
main:
	push   ebp
	mov    ebp,esp
	and    esp,0xfffffff0
	sub    esp,0x20
	lea    eax,[esp+0x18]
	mov    [esp+0x8],eax
	lea    eax,[esp+0x1c]
	mov    DWORD [esp+0x4],eax
	mov    DWORD [esp],fin
	call   scanf
	fld    DWORD [esp+0x18]
	fld    DWORD [esp+0x1c]
	fdivrp st1,st0
	fstp   QWORD [esp+0x4]
	mov    DWORD [esp],fout
	call   printf
	mov    eax,0x0
	push	0
	call	exit
