#include <Windows.h>
#include <stdio.h>

BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch(fdwReason){
        case DLL_PROCESS_ATTACH:
            MessageBoxA(0, "Inject Spy.dll", "SPY", MB_OK);
            break;
        case DLL_PROCESS_DETACH:
            MessageBoxA(0, "Eject Spy.dll", "SPY", MB_OK);
            break;
    }
    return TRUE;
}