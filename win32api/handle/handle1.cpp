// handle1.cpp

typedef int HWND;
typedef int HICON;

void MoveWindow(HWND hwnd, int x, int y)
{

}

HICON CreateIcon(){return 0;}

int main()
{
    HICON hIcon = CreateIcon();

    MoveWindow(hIcon, 10, 10); // 에러 발생이 없으며, 이는 버그로 이어진다.
}