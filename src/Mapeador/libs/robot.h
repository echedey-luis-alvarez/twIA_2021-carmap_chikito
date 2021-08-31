//Header that includes robot properties

#ifndef ROBOTH
#define ROBOTH

#include "vector.h"

typedef struct _robot robot;

// Units of properties given in metrical system
struct _robot {
	// Physical properties
	struct {
		struct {
			double lineal, angular;
		} vel;

		struct {
			double lineal, angular;
		} accel;

		struct {
			double length, width, height, wheel_radius;
		} dim;

		struct {
			double frame, wheel;
		} mass;
	} physical;
	
	// Movement properties
	struct {
		double linMove, rotAngle;
	} defMoves;

	vector2D position, lastMove;
	double angle; // 0 rad = +OX, counter-clockwise
	char name[30];
};

struct _command {
	char type;
	union {
		double duration;
		unsigned long long int stps;
	} quantity;
};

void robot_scanf_s(robot*);
void robot_print_all(const robot*, unsigned char precision);
void robot_print_summary(const robot*, unsigned char precision);

#endif
