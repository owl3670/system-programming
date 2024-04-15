#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <WinSock2.h>
#include <stdio.h>
#include <stdlib.h>
#pragma comment(lib, "ws2_32.lib")

struct OVERLAPPED_PLUS : public OVERLAPPED {
    int sock;
    WSABUF wsaBuf;
};

DWORD __stdcall EchoThread(void* p) {
    HANDLE hPort = (HANDLE)p;
    WSAOVERLAPPED* pov;
    DWORD bytes;
    UINT64 key;

    while(1){
        GetQueuedCompletionStatus(hPort, &bytes, &key, &pov, INFINITE);

        OVERLAPPED_PLUS* op = (OVERLAPPED_PLUS*)pov;

        printf("수신된 data : %s\n", op->wsaBuf.buf);

        closesocket(op->sock);
        delete op->wsaBuf.buf;
        CloseHandle(op->hEvent);
        delete op;
    }
    return 0;
}

int main() {
    WSADATA w;
    int ret = WSAStartup(MAKEWORD(2, 2), &w);

    // 1. IOCP 생성
    HANDLE hPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, 2);

    // 2. IOCP에서 대기할 스레드 생성
    HANDLE h1 = CreateThread(0, 0, EchoThread, (void*)hPort, 0, 0);
    HANDLE h2 = CreateThread(0, 0, EchoThread, (void*)hPort, 0, 0);

    // Listen 소켓
    int listen_sock = WSASocketW(PF_INET, SOCK_STREAM, 0, 0, 0, WSA_FLAG_OVERLAPPED);
    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(4000);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(listen_sock, (struct sockaddr*)&addr, sizeof addr);
    listen(listen_sock, 5);

    int cnt = 0;
    while(1){
        struct sockaddr_in addr2;
        int sz = sizeof addr2;

        // Client 대기.
        int link_sock = accept(listen_sock, (struct sockaddr*)&addr2, &sz);

        CreateIoCompletionPort((HANDLE)link_sock, hPort, link_sock, 2);

        printf("클라이언트가 접속되었습니다.\n");

        // IO작업당 아래 구조체를 만들어서 사용한다.
        OVERLAPPED_PLUS* op = new OVERLAPPED_PLUS;
        op->wsaBuf.buf = new char[1024];
        op->wsaBuf.len = 1024;
        op->hEvent = WSACreateEvent();

        DWORD flag = 0;
        DWORD recvBytes = 0;

        int n = WSARecv(link_sock,
                        &(op->wsaBuf), 1,
                        &recvBytes,
                        &flag,
                        op,
                        0);
    }
    WSACleanup();
}