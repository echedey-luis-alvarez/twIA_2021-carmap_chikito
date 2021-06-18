/* This library handles the console output map
*/

#include "mapper.h"

void map_mapAxisPrint(mapGrid* mg) {
    short minDim = min(mg->originX, mg->originY);
    for (int i = 0; i <= 4 * minDim; i++) {
        gotoxy(i, mg->originY);
        putchar(196);
    }
    for (int i = - minDim; i <= minDim; i++) {
        gotoxy(2 * mg->originX, mg->originY + i);
        putchar('|');
    }
    gotoxy(2 * mg->originX, mg->originY);
    putchar('O');
    return;
}

void map_charPrint(mapGrid* mg, mapCharObj* mc) {
    short x = rint(((double)mg->originX + mc->x) * 2),
        y = rint(((double)mg->originY) - mc->y);
    gotoxy(
        x,
        y
    );
    putchar(mc->c);
    return;
}

void map_rbPrint(mapGrid* mg, mapRbObj* mr) {
    map_charPrint(mg, &mr->center);
    map_charPrint(mg, &mr->dir);
    return;
}

void map_rbPrintFromRobot(mapGrid* mg, robot* rb) {
    mapRbObj mr = { 0 };
    mr.center = {
        (short)rint(rb->position.x / rb->defMoves.linMove),
        (short)rint(rb->position.y / rb->defMoves.linMove),
        '#'
    };
    mr.dir = {
        mr.center.x + (short)rint(cos(rb->angle)),
        mr.center.y + (short)rint(sin(rb->angle)),
        '+'
    };
    
    map_rbPrint(mg, &mr);
    return;
}
