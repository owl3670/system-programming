// handle2.cpp

//typedef int HWND;
//typedef int HICON;

struct HWND__
{
};
typedef struct HWND__* HWND;

struct HICON__
{
};
typedef struct HICON__* HICON;

void MoveWindow(HWND hwnd, int x, int y)
{

}

HICON CreateIcon(){return 0;}

int main()
{
    HICON hIcon = CreateIcon();

    MoveWindow(hIcon, 10, 10); // 컴파일 에러가 발생한다.
}