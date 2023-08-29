#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

int main()
{
    SECURITY_ATTRIBUTES sa = {0};
    sa.bInheritHandle = TRUE; // 상속 여부
    sa.lpSecurityDescriptor = 0;
    sa.nLength = sizeof(sa);

    HANDLE hFile = CreateFile(_T("b.txt"),
                GENERIC_READ | GENERIC_WRITE,
                FILE_SHARE_READ | FILE_SHARE_WRITE,
                &sa,
                CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );

    CloseHandle(hFile);
}
