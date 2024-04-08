#include <Windows.h>
#include <stdio.h>
#include <conio.h>

int main() {
    HANDLE hFile = CreateFileA("C:\\Windows\\system32\\calc.exe",
                               GENERIC_READ, FILE_SHARE_READ,
                               0, OPEN_EXISTING,
                               FILE_FLAG_OVERLAPPED, 0);

    char buff[4096] = {0};

    OVERLAPPED ov = {0};
    ov.hEvent = CreateEvent(0, 0, 0, 0);

    BOOL ret = ReadFile(hFile, buff, 4096, 0, &ov);

    if (ret == FALSE) {
        if(GetLastError() == ERROR_IO_PENDING){
            printf("start read asynchronous\n");

            WaitForSingleObject(ov.hEvent, INFINITE);
            printf("complete io\n");
        }else{
            printf("Read Error\n");
        }
    }

    CloseHandle(hFile);
    _getch();
}