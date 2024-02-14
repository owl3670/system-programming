#include <Windows.h>
#include <stdio.h>

int main(){
    const char* dllname = "D:\\Spy.dll";

    // Step 1. 메모장의 프로세스 핸들 얻기
    HWND hwnd = FindWindowA("Notepad", 0);

    DWORD pid;
    DWORD tid = GetWindowThreadProcessId(hwnd, &pid);

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    printf("%x, %x, %x\n", hwnd, pid, hProcess);

    // Step 2. LoadLibrary() 함수의 주소 얻기
    HMODULE hDll = GetModuleHandleA("kernel32.dll");

    PTHREAD_START_ROUTINE f = (PTHREAD_START_ROUTINE) GetProcAddress(hDll, "LoadLibraryA");

    printf("%p, %p\n", hDll, f);
}