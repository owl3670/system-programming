// findwindow.cpp
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

int main()
{
    HWND hwnd = FindWindow(0, _T("제목 없음 - 메모장"));
    printf("%d\n", hwnd)

    getchar();
    MoveWindow(hwnd, 0, 0, 500, 500, TRUE);
    getchar();
    ShowWindow(hwnd, SW_HIDE);
    getchar();
    ShowWindow(hwnd, SW_SHOW);
    getchar();
    SetMenu(hwnd, 0);

    POINT pt = { 10, 10 };
    HWND hwnd2 = WindowFromPoint(pt);
    printf("%d\n", hwnd2);
}