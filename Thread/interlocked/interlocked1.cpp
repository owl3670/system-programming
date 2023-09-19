#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <process.h>

LONG x = 0;

UINT __stdcall foo(void *p) {
    for (int i = 0; i < 1000000; i++) {
//        x = x + 1;
//        __asm
//        {
//                mov eax, x
//                add eax, 1
//                mov x, eax
//        }

        // Single CPU 에서는 안전
//        __asm
//        {
//                inc x
//        }

        // 코어 상관없이 안전
//        __asm
//        {
//                lock inc x
//        }

        InterlockedIncrement(&x);
    }
    return 0;
}

int main() {
    HANDLE h1 = (HANDLE) _beginthreadex(0, 0, foo, 0, 0, 0);
    HANDLE h2 = (HANDLE) _beginthreadex(0, 0, foo, 0, 0, 0);
    HANDLE h3 = (HANDLE) _beginthreadex(0, 0, foo, 0, 0, 0);

    HANDLE h[3] = {h1, h2, h3};

    WaitForMultipleObjects(3, h, TRUE, INFINITE);
    printf("result : %d\n", x);
    return 0;
}
