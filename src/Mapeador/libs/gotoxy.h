#ifndef GOTOXY
#define GOTOXY

#include <Windows.h>

void gotoxy(short x, short y);
void gotoxy_coord(const PCOORD);

void getCursorPos(PCOORD pCoord);

#endif // !GOTOXY
