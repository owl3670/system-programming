#include <Windows.h>
#include <stdio.h>

int main(){
    const char* dllname = "D:\\Spy.dll";

    HWND hwnd = FindWindowA("Notepad", 0);

    DWORD pid;
    DWORD tid = GetWindowThreadProcessId(hwnd, &pid);

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    printf("%x, %x, %x\n", hwnd, pid, hProcess);
}