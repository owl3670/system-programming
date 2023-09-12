#include <stdio.h>
#include <windows.h>
#include <tchar.h>

int main() {
    HANDLE hSem = CreateSemaphoreEx(0,
                                    3, 3,
                                    _T("MySem"),
                                    0,
                                    SEMAPHORE_ALL_ACCESS);

    WaitForSingleObject(hSem, INFINITE);

    MessageBoxA(0, "Release ?", "", MB_OK);
    LONG old;
    ReleaseSemaphore(hSem, 1, &old);

    return 0;
}
