#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <process.h>

void delay() {for(int i=0; i< 2000000; i++);}

// 1. 전역 구조체 만들기.
CRITICAL_SECTION cs;

UINT __stdcall foo(void* p)
{
    static int x = 0;

    for (int i = 0; i < 20; i++)
    {
        // 3. CriticalSection 접근
        EnterCriticalSection(&cs);
        //--------------------
        x = 100; delay();
        x = x + 1; delay();
        printf("%s : %d\n", p, x);
        //--------------------
        // 4. CriticalSection 탈출
        LeaveCriticalSection(&cs);
    }
    return 0;
}

int main()
{
    // 2. 초기화
//    InitializeCriticalSection(&cs);
    InitializeCriticalSectionAndSpinCount(&cs, 4000);

    HANDLE h1 = (HANDLE) _beginthreadex(0, 0, foo, (void*)"A", 0, 0);
    HANDLE h2 = (HANDLE) _beginthreadex(0, 0, foo, (void*)"\tB", 0, 0);

    HANDLE h[2] = {h1, h2};
    WaitForMultipleObjects(2, h, TRUE, INFINITE);
    CloseHandle(h1);
    CloseHandle(h2);

    // 5. 삭제
    DeleteCriticalSection(&cs);

    return 0;
}