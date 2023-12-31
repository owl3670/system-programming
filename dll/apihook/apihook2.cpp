// 32bit debug 모드
#include <Windows.h>
#include <stdio.h>

// MessageBoxA 를 후킹할 함수
// MessageBoxA 함수의 모양(signature)가 동일 해야 한다.
UINT __stdcall foo(HWND hwnd, const char* s1, const char* s2, UINT btn){
    printf("foo : %s, %s\n", s1, s2);
    return 0;
}

int main(){
    // MessageBoxA 의 주소를 담은 IAT 항목을 덮어쓴다.
    // 주소값이 계속 바뀌기에 IDE 에서 옵션 값으로 바뀌지 않게 하여야 한다.
    DWORD old;
    VirtualProtect((void*)0x041B09C, sizeof(void*), PAGE_READWRITE, &old);
    *((int*)0x041B09C) = (int)&foo;

    MessageBoxA(0, "API Hooking", "AAA", 0);
}