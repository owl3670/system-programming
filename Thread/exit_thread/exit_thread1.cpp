#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <process.h>

struct Test
{
    Test() {printf("test()\n");}
    ~Test() {printf("~Test()\n");}
};
UINT __stdcall foo(void* p)
{
    Test t;

    //ExitThread(0);
    //_endthreadex(0);

    return 0;
}
int main()
{
    HANDLE hThread = (HANDLE)_beginthreadex(0, 0, foo, 0, 0, 0);
    TerminateThread(hThread, 0);

    getchar();
}