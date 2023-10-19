#include <Windows.h>
#include <stdio.h>

void print_module_address(const char* name)
{
    HANDLE hMode = GetModuleHandleA(name);

    if (name == 0) name = ".exe";

    printf("%15s : %p\n", name, hMode);
}

int main()
{
    HANDLE h = GetModuleHandleA("user32.dll");

    print_module_address(0); // exe 의 가상주소
    print_module_address("kernel32.dll");
    print_module_address("user32.dll");
    print_module_address("gdi32.dll");
    print_module_address("ntdll.dll");

    ShowWindow(0, 0);
}