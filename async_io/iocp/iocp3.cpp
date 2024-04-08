#include <Windows.h>
#include <stdio.h>
#include <conio.h>

struct OVERLAPPED_PLUS : public OVERLAPPED{
    HANDLE hFile;
    char* buff;
};

DWORD __stdcall foo(void* p){
    OVERLAPPED_PLUS* pOv = (OVERLAPPED_PLUS*) p;

    WaitForSingleObject(pOv->hEvent, INFINITE);

    printf("foo    : I/O Complete\n");
    printf("error  : %d\n", pOv->Internal);
    printf("bytes  : %d\n", pOv->InternalHigh);

    // buffer 사용

    delete pOv->buff; // buffer delete
    CloseHandle(pOv->hFile);

    return 0;
}

int main() {
    HANDLE hFile = CreateFileA("C:\\Windows\\system32\\calc.exe",
                               GENERIC_READ, FILE_SHARE_READ,
                               0, OPEN_EXISTING,
                               FILE_FLAG_OVERLAPPED, 0);

    OVERLAPPED_PLUS* op = new OVERLAPPED_PLUS;
    memset(op, 0, sizeof(OVERLAPPED_PLUS));
    op->hFile = hFile;
    op->buff = new char[4096];
    op->hEvent = CreateEvent(0, 0, 0, 0);

    BOOL ret = ReadFile(hFile, op->buff, 4096, 0, op);

    if (ret == FALSE) {
        if(GetLastError() == ERROR_IO_PENDING){
            printf("start read asynchronous\n");

            CreateThread(0, 0, foo, op, 0, 0);
        }else{
            printf("Read Error\n");
        }
    }

    CloseHandle(hFile);
    _getch();
}