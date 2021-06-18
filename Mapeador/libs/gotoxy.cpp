#include "gotoxy.h"

void gotoxy(short x, short y)
{
    HANDLE stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(stdoutHandle, { x, y });
    return;
}
