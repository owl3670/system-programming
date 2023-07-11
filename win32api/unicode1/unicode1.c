// unicode1.c
#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "abcd가나다라";

    printf("%d\n", sizeof(s)); // 13
    printf("%d\n", strlen(s)); // 12
}