#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

DWORD __stdcall foo(void* p)
{
    return 0;
}

int _tmain()
{
    DWORD tid;

    HANDLE handle = CreateThread(0, 0, foo, 0, 0, &tid);

    CloseHandle(handle);
    getchar();
}