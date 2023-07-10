// unicode2.c
#include <stdio.h>
#include <string.h>
#include <Windows.h>

int main() {
    char s[] = "abcd가나다라"; // DBCS

    char *p = s;

    while (*p != 0) {
        printf("%s]\n", p);

//        p++; // 문제 발생 코드

//        if (IsDBCSLeadByte(*p))
//            p += 2;
//        else
//            p += 1;

        p = CharNextA(p);
    }
}