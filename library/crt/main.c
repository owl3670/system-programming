// main.c
#include <stdio.h>
#include <Windows.h>

//#pragma comment(lib, "user32.lib")

int main()
{
    MessageBoxA(0, "A", "B", MB_OK);

    printf("Hello, C\n"); // C 표준 함수, CRT 함수
}