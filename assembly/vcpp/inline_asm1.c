#include <stdio.h>

int Add(int a, int b) {
    int c = a + b;

    __asm
    {
        mov eax, c
    }
}

int main() {
    int n = 0;

    Add(1, 2);

    __asm
    {
        mov n, eax
    }

    printf("n = %d\n", n);
}
