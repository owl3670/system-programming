// calling_convention1.c
void f1(int n, ...){}
void __stdcall f2(int n, ...){}
void __fastcall f3(int n, ...){}

int main()
{
    f1(1, 2);
    f1(1, 2, 3, 4);

    f2(1, 2);
    f2(1, 2, 3, 4);

    f3(1, 2);
    f3(1, 2, 3, 4);
}
