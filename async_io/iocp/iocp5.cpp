#include <Windows.h>
#include <stdio.h>
#include <conio.h>

struct OVERLAPPED_PLUS : public OVERLAPPED {
    int id;
    HANDLE hFile;
    char *buff;

    OVERLAPPED_PLUS() { memset(this, 0, sizeof(OVERLAPPED_PLUS)); }
};

BOOL Read4kAsync(HANDLE hFile, int offset, int id) {
    OVERLAPPED_PLUS *op = new OVERLAPPED_PLUS;
    op->id = id;
    op->hFile = hFile;
    op->buff = new char[4096];
    op->hEvent = CreateEvent(0, 0, 0, 0);
    return ReadFile(op->hFile, op->buff, 4096, 0, op);
}

DWORD __stdcall foo(void *p) {
    HANDLE hIOCP = (HANDLE) p;

    DWORD bytes = 0;
    DWORD error = 0;
    UINT64 key = 0;
    OVERLAPPED_PLUS *op = 0;

    while (GetQueuedCompletionStatus(hIOCP, &bytes, &key, (OVERLAPPED **) &op, INFINITE)) {
        printf("COMPLETE : %d, %d, %d\n", key, op->id, bytes);

        delete op->buff;
        delete op;
    }
    return 0;
}

int main() {
    // 1. IOCP 생성
    HANDLE hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, 2);

    HANDLE hFile1 = CreateFileA("C:\\Windows\\system32\\calc.exe",
                                GENERIC_READ, FILE_SHARE_READ,
                                0, OPEN_EXISTING,
                                FILE_FLAG_OVERLAPPED, 0);

    HANDLE hFile2 = CreateFileA("C:\\Windows\\system32\\notepad.exe",
                                GENERIC_READ, FILE_SHARE_READ,
                                0, OPEN_EXISTING,
                                FILE_FLAG_OVERLAPPED, 0);

    // 2. IOCP 에 장치 등록
    CreateIoCompletionPort(hFile1, hIOCP, 100, 2);
    CreateIoCompletionPort(hFile2, hIOCP, 200, 2);

    // 3. IOCP 에서 완료 큐를 대기할 스레드 생성
    HANDLE hThread1 = CreateThread(0, 0, foo, (void *) hIOCP, 0, 0);
    HANDLE hThread2 = CreateThread(0, 0, foo, (void *) hIOCP, 0, 0);

    // 비동기 요청 ...
    Read4kAsync(hFile1, 0, 1);
    Read4kAsync(hFile1, 4096, 2);
    Read4kAsync(hFile2, 0, 3);
    Read4kAsync(hFile2, 4096, 4);

    printf("Main Continue...\n");

    _getch();
}