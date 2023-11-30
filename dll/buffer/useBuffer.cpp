#include <Windows.h>
#include <stdio.h>
#include <process.h>
#include <conio.h>

extern "C" __declspec(dllimport) void SetData(const char *s);
extern "C" __declspec(dllimport) void GetData(char *s);

#pragma comment(lib, "buffer2.lib")

//스레드로 수행할 함수
UINT __stdcall foo(void) {
    char s[256];
    SetData("Hello");

    Sleep(1000);

    GetData(s);

    printf("foo : %s\n", s);
    return 0;
}

int main() {
    char s[256];
    SetData("AAA"); // DLL 버퍼에 보관

    _beginthreadex(0, 0, foo, 0, 0, 0);

    Sleep(300);

    GetData(s);

    printf("main : %s\n", s);

    _getch();
}