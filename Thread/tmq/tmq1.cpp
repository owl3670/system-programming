#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <process.h>

UINT __stdcall foo(void* p)
{
//    HWND hwnd = CreateWindowEx(0, _T("button"), _T("ok"), WS_OVERLAPPEDWINDOW,
//                               0, 0, 300, 300, 0, 0, 0, 0);
//    ShowWindow(hwnd, SW_SHOW);

    while (1)
    {
        MSG msg;
        GetMessage(&msg, 0, 0, 0);

        if (msg.message == WM_APP + 100)
        {
            printf("메세지 도착");
        }
        else if (msg.message == WM_APP + 200)
            break;

        printf("foo\n");
    }
    return 0;
}
int main()
{
    UINT tid = 0;
    HANDLE h = (HANDLE) _beginthreadex(0, 0, foo, 0, 0, &tid);

    Sleep(1000);
    BOOL b = PostThreadMessage(tid, WM_APP + 100, 10, 20);
    printf("result : %d\n", b);

    getchar();
    PostThreadMessage(tid, WM_APP + 200, 10, 20);

    WaitForSingleObject(h, INFINITE);
    CloseHandle(h);
    return 0;
}
