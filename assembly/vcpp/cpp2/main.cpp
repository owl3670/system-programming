// main.cpp
#include <stdio.h>

// extern "C" int asm_main();

int asm_main();

int main()
{
    int n = asm_main();

    printf("n = %d\n", n);
}