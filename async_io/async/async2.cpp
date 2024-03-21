#include <Windows.h>
#include <stdio.h>
#include <conio.h>

int main(){
    HANDLE hFile = CreateFileA("C:\\Windows\\system32\\calc.exe",
                               GENERIC_READ, FILE_SHARE_READ,
                               0, OPEN_EXISTING,
                               FILE_FLAG_OVERLAPPED, 0);

    if(hFile == INVALID_HANDLE_VALUE){
        printf("Error in Open File\n");
    }

    DWORD len = 0;
    char buff[4096] = { 0 };

    OVERLAPPED ov = { 0 };

    BOOL ret = ReadFile(hFile, buff, 4096, 0, &ov);

    if (ret == FALSE){
        if (GetLastError() == ERROR_IO_PENDING){
            printf("Start Read Asynchronous\n");
        } else {
            printf("Read Error\n");
        }
    } else {
        printf("Completing writes synchronously\n");
    }

    CloseHandle(hFile);
    _getch();
}