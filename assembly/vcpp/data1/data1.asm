; data1.asm
.model flat
public _asm_main

.data
L1 DWORD 100
L2 DD    200
L3 DD    ? ; 메모리는 할당되나 값이 정해지지 않음
L4 DD 100, 200, 300, 400
L5 DD 4 dup (100) ; 100, 100, 100, 100
L6 DD 4 dup (?) ; 길이는 4이나 값이 정해지지 않음

.code
_asm_main:
    ;L1 = 300
    mov L1, 300

    ; L1 = L2
    ;mov L1, L2
    mov ebx, L2
    mov L1, ebx

    mov ebx, offset L1
    mov dword ptr[ebx], 300  ; mov L1, 300
    mov eax, [ebx]

    mov esi, offset L4
    mov eax, dword ptr[esi + 8]

    ret
end