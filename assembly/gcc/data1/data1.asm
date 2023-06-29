; data1.asm
global asm_main

section .data
L1 DD    100
L2 DD    200
L3 DD    ? ; 메모리는 할당되나 값이 정해지지 않음
L4 DD 100, 200, 300, 400
L5 times 4 DD 100 ; 100, 100, 100, 100
L6 times 4 DD ? ; 길이는 4이나 값이 정해지지 않음

section .text
asm_main:
    ;L1 = 300
    mov dword [L1], 300

    ; L1 = L2 ;mov L1, L2
    mov ebx, dword [L2]
    mov dword [L1], ebx

    mov ebx, L1
    mov dword [ebx], 300  ; mov L1, 300
    mov eax, dword [ebx]

    mov esi, dword [L4]
    mov eax, dword [esi + 8]

    ret