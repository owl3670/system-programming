#include <Windows.h>
#include <stdio.h>
#include <conio.h>

void __stdcall foo(DWORD error, DWORD bytes, LPOVERLAPPED ov) {
    printf("foo\n");
    printf("error : %d\n", error);
    printf("bytes : %d\n", bytes);
}

int main() {
    HANDLE hFile = CreateFileA("C:\\Windows\\system32\\calc.exe",
                               GENERIC_READ, FILE_SHARE_READ,
                               0, OPEN_EXISTING,
                               FILE_FLAG_OVERLAPPED, 0);

    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Error in Open File\n");
    }

    DWORD len = 0;
    char buff[4096] = {0};

    OVERLAPPED ov = {0};
    ov.hEvent = CreateEvent(0, 0, 0, 0);

//    BOOL ret = ReadFile(hFile, buff, 4096, 0, &ov);
    BOOL ret = ReadFileEx(hFile, buff, 4096, &ov, foo);

    if (ret == TRUE) {
        printf("Start Read Asynchronous\n");
    } else {
        printf("Read Error\n");
    }

    SleepEx(10000, TRUE);

    CloseHandle(hFile);
    _getch();
}