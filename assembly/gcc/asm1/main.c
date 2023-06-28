// main.c
#include <stdio.h>

int asm_main();

int main()
{
    int n = 0;
    n = asm_main();

    printf("n = %d\n", n);
}