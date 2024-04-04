#include <Windows.h>
#include <stdio.h>
#include <conio.h>

int main() {
    HANDLE hFile = CreateFileA("C:\\Windows\\system32\\calc.exe",
                               GENERIC_READ, FILE_SHARE_READ,
                               0, OPEN_EXISTING,
                               FILE_FLAG_OVERLAPPED, 0);

    DWORD len = 0;
    char buff[4096] = {0};

    OVERLAPPED ov = {0};
    ov.hEvent = CreateEvent(0, 0, 0, 0);

    BOOL ret = ReadFile(hFile, buff, 4096, 0, &ov);

    if (ret == FALSE) {
        if(GetLastError() == ERROR_IO_PENDING){
            printf("start read asynchronous\n");

            WaitForSingleObject(ov.hEvent, INFINITE);
            printf("complete io\n");

            printf("Error : %d\n", ov.Internal);
            printf("Bytes : %d\n", ov.InternalHigh);

            DWORD bytes = 0;
            GetOverlappedResult(hFile, &ov, &bytes, TRUE);
            printf("Bytes : %d\n", bytes);


        }else{
            printf("Read Error\n");
        }
    }

    CloseHandle(hFile);
    _getch();
}