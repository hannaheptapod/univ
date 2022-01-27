#include <iostream>
#include "stdafx.h"
#include <conio.h>

HANDLE g_hPort;

int initialize();
void cleanup();

int _tmain(int argc, _TCHAR* argv[]) {
    int flag = 0;
    int cnt = 0;
    uint8_t uart;
    uint16_t vol;

    if (initialize() < 0) return -1;

    while (!flag) {
        DWORD dwReadBytes;
        if (ReadFile(g_hPort, &uart, 1, &dwReadBytes, NULL) == 0) flag = 0;
        else if (!cnt) {
            vol = uart << 8;
            cnt++;
        }
        else {
            vol += uart;
            std::cout << "Current: " << vol << std::endl;
            cnt = 0;
        }
        Sleep(50);
    }

    cleanup();
    return 0;
}

int initialize() {
    DCB dcb; BOOL result;
    g_hPort = CreateFile(_T("COM3"),
        GENERIC_READ | GENERIC_WRITE, 0,
        NULL,
        OPEN_EXISTING,
        0, /*FILE_FLAG_OVERLAPPED,*/ NULL);
    if (g_hPort == INVALID_HANDLE_VALUE) {
        return -1;
    }
    GetCommState(g_hPort, &dcb);
    dcb.BaudRate = 9600;
    dcb.fParity = FALSE;
    dcb.Parity = NOPARITY;
    dcb.ByteSize = 8;
    dcb.StopBits = ONESTOPBIT;
    dcb.fOutxCtsFlow = FALSE;
    dcb.fOutxDsrFlow = FALSE;

    result = SetCommState(g_hPort, &dcb);
    if(!result) {
        return -1;
    }
    return 0;
}

void cleanup() {
    CloseHandle(g_hPort);
}
