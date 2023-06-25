; asm1.asm

global _asm_main

section .code               ; code segment

_asm_main:          ; function _asm_main
    mov eax, 100    ; return 100
    ret
