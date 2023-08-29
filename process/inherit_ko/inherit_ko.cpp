#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

LRESULT __stdcall WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    static HWND hEdit;

    switch (message) {
        case WM_CREATE:
            hEdit = CreateWindowEx(0, _T("edit"), _T(""),
                                   ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_BORDER,
                                   10, 10, 300, 500, hwnd, (HMENU) 1, 0, 0);
            break;

        case WM_LBUTTONDOWN: {
            HANDLE hFile = CreateFile(_T("a.txt"), GENERIC_READ | GENERIC_WRITE,
                                      FILE_SHARE_READ | FILE_SHARE_WRITE, 0, CREATE_ALWAYS,
                                      FILE_ATTRIBUTE_NORMAL, 0);

            // Kernel Object 상속 여부
            SetHandleInformation(hFile,
                                 HANDLE_FLAG_INHERIT,
                                 HANDLE_FLAG_INHERIT);

            STARTUPINFO si = {0};
            si.cb = sizeof(si);

            si.hStdOutput = hFile;
            si.dwFlags = STARTF_USESTDHANDLES;

            PROCESS_INFORMATION pi = {0};

            TCHAR name[] = _T("ping www.microsoft.com");

            BOOL b = CreateProcess(0, name, 0, 0, TRUE,
                                   0, 0, 0, &si, &pi);

            if (b) {
                CloseHandle(pi.hProcess);
                CloseHandle(pi.hThread);
            }
        }
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}

int main() {
    WNDCLASSEX wcex = {0};
    wcex.cbSize = sizeof(wcex);
    wcex.lpfnWndProc = WndProc;
    wcex.lpszClassName = _T("MyWindow");
    wcex.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
    wcex.hCursor = LoadCursor(0, IDC_ARROW);

    ATOM atom = RegisterClassEx(&wcex);

    HWND hwnd = CreateWindowEx(0,
                               _T("MyWindow"),
                               _T("Hello Win32"),
                               WS_OVERLAPPEDWINDOW,
                               0, 0, 500, 500,
                               0, 0, 0, 0);

    ShowWindow(hwnd, SW_SHOW);
    // -------------------------

    // 메세지 큐에서 메세지를 꺼내온다.
    // MessageLoop
    MSG msg;
    while (GetMessage(&msg, 0, 0, 0))
    {
        // 윈도우 클래스에 등록된 함수로 전달
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
