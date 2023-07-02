; asm1.asm
model flat

public _asm_main

.code

_asm_main:
	mov eax, 100

	; mov eax, POS_A
	push POS_A
	jmp _add
POS_A:
	ret

_add:
	mov eax, 300

	pop ebx
	jmp ebx ; 해당 주소로 jump 하라는 의미

end