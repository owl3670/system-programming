#include <stdio.h>

int Add(int a, int b) {
    return  a + b;
}

int main() {
    int n = 0;

//    Add(1, 2);
    __asm
    {
        push 2
        push 1
        call Add
        add esp, 8

        mov n, eax
    }

    printf("n = %d\n", n);
}
