// findwindow2.cpp
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

int main()
{
    HWND hwnd = FindWindow(0, _T("제목 없음 - 메모장"));
    printf("%d\n", hwnd)

    getchar();
    DestroyWindow(hwnd); // 다른 스레드에서 생성된 윈도우는 파괴할 수 없다.
}