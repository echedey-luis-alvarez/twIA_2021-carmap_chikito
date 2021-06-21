#ifndef GOTOXY
#define GOTOXY

#include <Windows.h>

void gotoxy(short x, short y);
void gotoxy(COORD);

void getCursorPos(PCOORD pCoord);

#endif // !GOTOXY
