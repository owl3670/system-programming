// unicode3.cpp
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <tchar.h>

//#define _UNICODE
//
//#ifdef _UNICODE
//    typedef wchar_t TCHAR;
//    #define _T(x) L##x
//    #define _tcslen wcslen
//    #define _tprintf wprintf
//#else
//    typedef char TCHAR;
//    #define _T(x) x
//    #define _tcslen strlen
//    #define _tprintf printf
//#endif
//
//#ifdef UNICODE
//    #define MessageBox MessageBoxW
//#else
//    #define MessageBox MessageBoxA
//#endif

int main()
{
    TCHAR s[] = _T("abcd가나다라");

    _trpintf(_T("%d\n"), _tcslen(s));

    MessageBox(0, "A", "B", MB_OK);
}