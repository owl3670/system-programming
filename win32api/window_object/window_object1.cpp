// window_object1.cpp
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

int main()
{
    HWND hwnd = FindWindow(_T("Notepad"), 0);

    getchar();

    LONG style = GetWindowLongPtr(hwnd, GWL_STYLE);
//    style = style | WS_CAPTION; // 스타일 추가
    style = style & ~WS_CAPTION; // 스타일 제거
    style = style & ~WS_THICKFRAME; // 스타일 제거

    SetWindowLongPtr(hwnd, GWL_STYLE, style);

    // 스타일을 변경한 경우 강제로 다시 그리게 한다.
    SetWindowPos(hwnd, 0, 0, 0, 0, 0, SWP_NOZORDER | SW_NOMOVE | SWP_NOSIZE | SWP_DRAWFRAME);
}