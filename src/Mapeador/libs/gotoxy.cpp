#include "gotoxy.h"

void gotoxy(short x, short y)
{
    COORD p = { x, y };
    gotoxy_coord(&p);

    return;
}

void gotoxy_coord(const PCOORD p)
{
    HANDLE stdoutH = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(stdoutH, *p);
    return;
}

void getCursorPos(PCOORD pCoord) {
    HANDLE stdoutH = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO cInfo;

    GetConsoleScreenBufferInfo(stdoutH, &cInfo);

    *pCoord = cInfo.dwCursorPosition;
    return;
}
