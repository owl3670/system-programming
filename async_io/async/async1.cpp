#include <Windows.h>
#include <stdio.h>
#include <conio.h>

int main(){
    HANDLE hFile = CreateFileA("C:\\Windows\\system32\\calc.exe",
                               GENERIC_READ, FILE_SHARE_READ,
                               0, OPEN_EXISTING,
                               FILE_ATTRIBUTE_NORMAL, 0);

    if(hFile == INVALID_HANDLE_VALUE){
        printf("Error in Open File\n");
    }

    DWORD len = 0;
    char buff[4096] = { 0 };
    BOOL ret = ReadFile(hFile, buff, 4096, &len, 0);

    if (ret == FALSE){
        printf("Read Error\n");
    } else {
        printf("Completing writes synchronously\n");
    }

    CloseHandle(hFile);
    _getch();
}