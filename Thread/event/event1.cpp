#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <process.h>

HANDLE hEvent = 0;

UINT __stdcall foo(void* p)
{
    WaitForSingleObject(hEvent, INFINITE);
    printf("foo start work\n");
    return 0;
}
int main()
{
    hEvent = CreateEventEx(0, _T("MyEvent"),
                           0, // 초기 시그널 상태와 reset 의 종류 (0: non signal, auto reset)
                           EVENT_ALL_ACCESS);

    HANDLE hThread = (HANDLE) _beginthreadex(0, 0, foo, 0,
                                             0, 0);

    getchar();

    SetEvent(hEvent);

    getchar();
    CloseHandle(hEvent);
    CloseHandle(hThread);
    return 0;
}