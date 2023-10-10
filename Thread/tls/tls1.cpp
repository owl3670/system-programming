#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <process.h>

int next3times()
{
//    int n = 0;
//    static int n = 0; // 모든 스레드에서 공유

    __declspec(thread) static int n = 0; // TLS 사용

    n = n + 3;
    return n;
}

UINT __stdcall foo(void* p)
{
    printf("%s : %d\n", p, next3times());
    printf("%s : %d\n", p, next3times());
    printf("%s : %d\n", p, next3times());
    return 0;
}

int main()
{
    HANDLE h1 = (HANDLE) _beginthreadex(0, 0, foo, (void*)"A", 0, 0);
    HANDLE h2 = (HANDLE) _beginthreadex(0, 0, foo, (void*)"\tA", 0, 0);

    getchar();

    return 0;
}