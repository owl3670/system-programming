#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <process.h>

//DWORD __stdcall foo(void* p)
unsigned int __stdcall foo(void* p)
{
    return 0;
}

int _tmain()
{
//    DWORD tid;
//    unsigned int tid;
    UINT tid;

//    HANDLE handle = CreateThread(0, 0, foo, 0, 0, &tid);
    HANDLE handle = (HANDLE) _beginthreadex(0, 0, foo, 0, 0, &tid);

    CloseHandle(handle);

    getchar();
}