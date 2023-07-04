// calling_convention1.c
#include <stdio.h>

int add(int a, int b)
{
    int c = a + b;
    return c;
}

int main()
{
    int ret = 0;

    ret = add(1, 2);

    printf("ret = %d\n", ret);
}