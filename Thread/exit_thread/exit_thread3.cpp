#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <process.h>

UINT __stdcall foo(void* p)
{
    Sleep(3000);

    return 100;
}
int main()
{
    HANDLE hThread = (HANDLE)_beginthreadex(0, 0, foo, 0, 0, 0);

    DWORD ret = WaitForSingleObject(hThread, INFINITE);

    if(ret == WAIT_OBJECT_0)
    {
        DWORD code;
        GetExitCodeThread(hThread, &code);

        _tprintf(_T("result : %d\n"), code);
    }
    else if (ret == WAIT_TIMEOUT)
    {

    }
    CloseHandle(hThread);

    return 0;
}