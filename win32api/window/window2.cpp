// window2.cpp
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

int main() {
    WNDCLASSED wcex = {0};
    wcex.cbSize = sizeof(wcex);
    wcex.lpfnWndProc = DefWindowProc;
    wcex.lpszClassName = _T("MyWindow");
    wcex.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
    wcex.hCursor = LoadCursor(0, IDC_ARROW);

    ATOM atom = RegisterClassEx(&wcex);

    if (atom == 0) {
        printf("Register Failed : %d\n", GetLastError());
    }

    HWND hwnd = CreateWindowEx(0,
                   _T("MyWindow"),
                   _T("Hello Win32"),
                   WS_OVERLAPPEDWINDOW,
                   0, 0, 500, 500,
                   0, 0, 0, 0);

    ShowWindow(hwnd, SW_SHOW);
}