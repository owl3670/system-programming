#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <process.h>

void delay() {for(int i=0; i< 2000000; i++);}

UINT __stdcall foo(void* p)
{
    static int x = 0;

    for (int i = 0; i < 20; i++)
    {
        x = 100; delay();
        x = x + 1; delay();
        printf("%s : %d\n", p, x);
    }
    return 0;
}

int main()
{
    HANDLE h1 = (HANDLE) _beginthreadex(0, 0, foo, (void*)"A", 0, 0);
    HANDLE h2 = (HANDLE) _beginthreadex(0, 0, foo, (void*)"\tB", 0, 0);

    HANDLE h[2] = {h1, h2};
    WaitForMultipleObjects(2, h, TRUE, INFINITE);
    CloseHandle(h1);
    CloseHandle(h2);
    return 0;
}