#include "gotoxy.h"

void gotoxy(short x, short y)
{
    gotoxy({ x, y });

    return;
}

void gotoxy(COORD p)
{
    HANDLE stdoutH = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(stdoutH, p);
    return;
}

void getCursorPos(PCOORD pCoord) {
    HANDLE stdoutH = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO cInfo;

    GetConsoleScreenBufferInfo(stdoutH, &cInfo);

    *pCoord = cInfo.dwCursorPosition;
    return;
}
