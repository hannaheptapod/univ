#include <iostream>
#include "stdafx.h"
#include <conio.h>

HANDLE g_hPort;

int initialize();
void cleanup();
int readchar(unsigned char* c);
int writechar(unsigned char c);

int _tmain(int argc, _TCHAR* argv[]) {
    int flag = 0;
    unsigned char c;

    if (initialize() < 0) return -1;

    while (!flag) {
        if (_kbhit()) {
            c = _getch();
            switch (c) {
                case 'y':
                    writechar('1');
                    break;
                case 'n':
                    writechar('0');
                    break;
                case 'q':
                    flag = 1;
                    break;
                default:
                    printf("Unknown command.\n");
                    break;
            }
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

int readchar(unsigned char* c) {
    COMSTAT ComStat;
    DWORD dwError;
    DWORD dwReadBytes;

    ClearCommError(g_hPort, &dwError, &ComStat);
    if (ComStat.cbInQue >= 1 && ReadFile(g_hPort, c, 1, &dwReadBytes, NULL)) return dwReadBytes;
    return 0;
}

int writechar(unsigned char c) {
    DWORD dwWrittenBytes;

    if (WriteFile(g_hPort, &c, 1, &dwWrittenBytes, NULL) == 0) return -1;

    return dwWrittenBytes;
}