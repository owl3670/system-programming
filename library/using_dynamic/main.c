// main.c
#include <stdio.h>
#include "mymath.h"

#pragma commet(lib, "mymath.lib")

int main()
{
    int ret = add(1, 2);

    printf("ret = %d\n", ret);
}