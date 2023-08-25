#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

int main()
{
    PROCESS_INFORMATION pi = {0};
    STARTUPINFO si = {0};
    si.cb = sizeof (si);

    TCHAR name[] = _T("C:\\Users\\hsseo\\Desktop\\personal\\Sample.exe");
    TCHAR args[] = _T("Sample.exe B C D"); // argv[0] => A

    BOOL b = CreateProcess(name,
                           args,
                           0, 0,
                           FALSE, CREATE_NEW_CONSOLE,
                           0, 0, &si, &pi);
    if(b)
    {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}