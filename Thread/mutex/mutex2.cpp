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

    WaitForSingleObject(hMutex, INFINITE);
    printf("get mutex\n");
    MessageBoxA(0, "Release ?", "", MB_OK);

    WaitForSingleObject(hMutex, INFINITE);
    printf("get mutex\n");
    MessageBoxA(0, "Release ?", "", MB_OK);

    ReleaseMutex(hMutex);

    CloseHandle(hMutex);
}