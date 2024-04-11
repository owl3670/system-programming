#include <Windows.h>
#include <stdio.h>
#include <conio.h>

struct OVERLAPPED_PLUS : public OVERLAPPED{
    int id;
    HANDLE hFile;
    char* buff;
    OVERLAPPED_PLUS() {memset(this, 0, sizeof(OVERLAPPED_PLUS));}
};

BOOL Read4kAsync(HANDLE hFile, int offset, int id){
    OVERLAPPED_PLUS* op = new OVERLAPPED_PLUS;
    op->id = id;
    op-> hFile = hFile;
    op->buff = new char[4096];
    op->hEvent = CreateEvent(0, 0, 0, 0);
    return ReadFile(op->hFile, op->buff, 4096, 0, op);
}

int main() {
    HANDLE hFile1 = CreateFileA("C:\\Windows\\system32\\calc.exe",
                               GENERIC_READ, FILE_SHARE_READ,
                               0, OPEN_EXISTING,
                               FILE_FLAG_OVERLAPPED, 0);

    HANDLE hFile2 = CreateFileA("C:\\Windows\\system32\\notepad.exe",
                               GENERIC_READ, FILE_SHARE_READ,
                               0, OPEN_EXISTING,
                               FILE_FLAG_OVERLAPPED, 0);

    Read4kAsync(hFile1, 0, 1);
    Read4kAsync(hFile1, 4096, 2);
    Read4kAsync(hFile2, 0, 3);
    Read4kAsync(hFile2, 4096, 4);

    printf("Main Continue...\n");

    _getch();
}