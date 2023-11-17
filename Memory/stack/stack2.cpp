#include <stdio.h>
#include <windows.h>

int main() {
    char *p = (char *) VirtualAlloc(0, 1024 * 1024, MEM_RESERVE, PAGE_READWRITE);

    VirtualAlloc(p, 4096, MEM_COMMIT, PAGE_READWRITE);
    VirtualAlloc(p + 4096, 4096, MEM_COMMIT, PAGE_READWRITE | PAGE_GUARD);

    p[0] = 'A';
    p[4095] = 'B';

    __try{
            p[4096] = 'C';
    }
    __except(1)
    {
        printf("%x\n", GetExceptionCode()); // 80000001
        int n = EXCEPTION_GUARD_PAGE;
    }

    // 2PAGE 사용가능..
    p[4096] = 'C'; // PAGE_GUARD 속성일 때 접근 Exception 은 한 번만 발생한다.

    VirtualAlloc(p + 8192, 4096, MEM_COMMIT, PAGE_READWRITE | PAGE_GUARD);
}