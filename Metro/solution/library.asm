
global subroutine

SECTION .text
subroutine:
	push   ebx
    mov    ecx,DWORD [esp+0x8]
    mov    edx,DWORD [esp+0xc]
   	mov    ebx,ecx
    sub    ebx,edx
    cmp    ecx,edx
    lea    eax,[ecx+edx*1]
    cmovle eax,ebx
    pop    ebx
    ret    
