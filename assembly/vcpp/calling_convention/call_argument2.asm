; call_argument2.asm
.model flat
public _asm_main
.code

_asm_main:
    mov edx, 2
    mov ecx, 1
    call _add
    add esp, 8
    ret

_add:
    mov eax, dword ptr[esp+4]
    add eax, dword ptr[esp+8]
    ret

end