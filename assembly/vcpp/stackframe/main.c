// main.c
#include <stdio.h>

int asm_main();

int main()
{
    int ret = asm_main();

    printf("ret = %d\n", ret);
}