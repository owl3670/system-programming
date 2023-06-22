#include <stdio.h>

int Add(int a, int b) {
    int c = a + b;

    __asm__ __volatile__(
            "mov %%eax, %0\n\t"
            :"=r"(c)
            );
}

int main() {
    int n = 0;

    Add(1, 2);

    // mov n eax
    __asm__ __volatile__(
            "mov %0, %%eax\n\t"
            :"=r"(n)
            );

    printf("n = %d\n", n);
}
