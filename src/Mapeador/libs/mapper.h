/* This library handles the console output map
*/


#ifndef MAPPER_H
#define MAPPER_H

#include "robot.h"
#include "gotoxy.h"

#include <stdio.h>
#include <math.h>
#include <Windows.h>

typedef struct _mapGrid mapGrid;
typedef struct _mapCharObj mapCharObj;
typedef struct _mapRbObj mapRbObj;

struct _mapGrid {
	short originX, originY;
};

struct _mapCharObj {
	short x, y;
	char c;
};

struct _mapRbObj {
	mapCharObj center, dir;
};

void map_mapAxisPrint(const mapGrid*);
void map_charPrint(mapGrid*, const mapCharObj*);
void map_rbPrint(mapGrid*, mapRbObj*);
void map_rbPrintFromRobot(mapGrid*, const robot*);

#endif //!MAPPER_H
