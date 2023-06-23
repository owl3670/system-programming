#include <stdio.h>

int Add(int a, int b) {
    return  a + b;
}

int main() {
    int n = 0;

//    Add(1, 2);
    __asm__ __volatile__(
            "movl $1, %%edx\n\t"
            "movl $2, %%ecx\n\t"
            "call Add\n\t"
            "mov %0, %%eax \n\t"
            :"=r"(n)
            :
            );

    printf("n = %d\n", n);
}
