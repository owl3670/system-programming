// unicode2.cpp
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "abcd가나다라"; // DBCS

    wchar_t s2[] = L"abcd가나다라"; // Unicode

    printf("%d\n", sizeof(s2)); // 18
    printf("%d\n", strlen((char*)s2)); // 1
    printf("%d\n", wcslen(s2)); // 8

    printf("AA\n");
    wprintf(L"AA\n");
}