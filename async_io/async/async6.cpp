#include <Windows.h>
#include <stdio.h>
#include <conio.h>

int main() {
    HANDLE hFile = CreateFileA("C:\\Windows\\system32\\calc.exe",
                               GENERIC_READ, FILE_SHARE_READ,
                               0, OPEN_EXISTING,
                               FILE_FLAG_OVERLAPPED, 0);
    {
        char buff[4096] = {0};

        OVERLAPPED ov = {0};
        ov.hEvent = CreateEvent(0, 0, 0, 0);

        BOOL ret = ReadFile(hFile, buff, 4096, 0, &ov);
        // 블럭을 벗어나면 buffer 와 OVERLAPPED 구조체가 파괴됨
    }

    CloseHandle(hFile);
    _getch();
}