; stackframe3.asm
.model flat
public _asm_main
.code

_asm_main:
    push ebp
    mov ebp, esp

    ; _add(1,2)
    push 2
    push 1
    call _add
    add esp, 8

    mov esp, ebp
    pop ebp
    ret

x = -4
y = -8
a = 8
b = 12
_add:
push ebp
    mov ebp, esp

    ; 지역 변수 생성.
    sub esp, 8
    mov dword ptr x[ebp], 100
    mov dword ptr y[ebp], 200

    mov eax, dword ptr a[ebp]
    add eax, dword ptr b[ebp]

	mov esp, ebp ; 지역변수 파괴
    pop ebp
    ret
end