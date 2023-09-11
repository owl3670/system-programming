#include <stdio.h>
#include <windows.h>
#include <tchar.h>

int main()
{
    printf("try acquire mutex\n");

    HANDLE hMutex = CreateMutexEx(0,
                                  _T("MyMutex"),
                                  0, // CREATE_MUTEX_INITIAL_OWNER,
                                  MUTEX_ALL_ACCESS );

    // wait 로 mutex 통과시 스레드가 mutex 를 소유하게됨
    DWORD ret = WaitForSingleObject(hMutex, INFINITE);

    if(ret == WAIT_OBJECT_0)
    {
        printf("정상 획득\n");
    }
    else if (ret == WAIT_ABANDONED)
    {
        printf("포기된 뮤텍스 획득\n");
    }

    printf("get mutex\n");
    MessageBoxA(0, "Release ?", "", MB_OK);

//    ReleaseMutex(hMutex);

    CloseHandle(hMutex);
}