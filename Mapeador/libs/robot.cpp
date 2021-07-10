#include <stdio.h>
#include <stdlib.h>

#include "robot.h"

//function that ask for the properties of the robot
void robot_scanf_s(robot *r) {
	unsigned char status = 0;

	do {
		printf("Enter lineal velocity (m/s): ");
		fseek(stdin, 0, SEEK_END);
		status = scanf_s("%lf", &r->physical.vel.lineal);
	} while (status == 0);
	status = 0;

	do {
		printf("Enter angular velocity (rad/s): ");
		fseek(stdin, 0, SEEK_END);
		status = scanf_s("%lf", &r->physical.vel.angular);
	} while (status == 0);
	status = 0;

	do {
		printf("Enter lineal acceleration (m/s^2): ");
		fseek(stdin, 0, SEEK_END);
		status = scanf_s("%lf", &r->physical.accel.lineal);
	} while (status == 0);
	status = 0;

	do {
		printf("Enter angular acceleration (rad/s^2): ");
		fseek(stdin, 0, SEEK_END);
		status = scanf_s("%lf", &r->physical.accel.angular);
	} while (status == 0);
	status = 0;

	do {
		printf("Enter length (m): ");
		fseek(stdin, 0, SEEK_END);
		status = scanf_s("%lf", &r->physical.dim.length);
	} while (status == 0);
	status = 0;

	do {
		printf("Enter width (m): ");
		fseek(stdin, 0, SEEK_END);
		status = scanf_s("%lf", &r->physical.dim.width);
	} while (status == 0);
	status = 0;

	do {
		printf("Enter height (m): ");
		fseek(stdin, 0, SEEK_END);
		status = scanf_s("%lf", &r->physical.dim.height);
	} while (status == 0);
	status = 0;

	do {
		printf("Enter wheel radius (m): ");
		fseek(stdin, 0, SEEK_END);
		status = scanf_s("%lf", &r->physical.dim.wheel_radius);
	} while (status == 0);
	status = 0;

	do {
		printf("Enter structure mass (kg): ");
		fseek(stdin, 0, SEEK_END);
		status = scanf_s("%lf", &r->physical.mass.frame);
	} while (status == 0);
	status = 0;

	do {
		printf("Enter wheel mass (kg): ");
		fseek(stdin, 0, SEEK_END);
		status = scanf_s("%lf", &r->physical.mass.wheel);
	} while (status == 0);

	return;
}

//function that shows the properties of the robot
void robot_print_all(const robot* rb, unsigned char p) {
	printf("Robot \"%30s\" @", rb->name);
	vector2D_print(rb->position, p);
	printf("<%.*f\nProperties\n\
	Velocities:\n\
	\t - Lin: %.*f\n\
	\t - Ang: %.*f\n\
	Accelerations:\n\
	\t - Lin: %.*f\n\
	\t - Ang: %.*f\n\
	Mass:\n\
	\t - Frame: %.*f\n\
	\t - Wheel: %.*f\n\
	Dimensions:\n\
	\t - Wheel radius: %.*f\n\
	\t - Lenght: %.*f\n\
	\t - Widht: %.*f\n\
	\t - Height: %.*f\n\
	Default movements:\n\
	\t - Lineal: %.*f\n\
	\t - Angular: %.*f\n\
	SI Units\n", 
		p, rb->angle,
		p, rb->physical.vel.lineal, p, rb->physical.vel.angular,
		p, rb->physical.accel.lineal, p, rb->physical.accel.angular,
		p, rb->physical.mass.frame, p, rb->physical.mass.wheel,
		p, rb->physical.dim.wheel_radius, p, rb->physical.dim.length, p, rb->physical.dim.width, p, rb->physical.dim.height,
		p, rb->defMoves.linMove, p, rb->defMoves.rotAngle);

	return;
}

void robot_print_summary(const robot* rb, unsigned char p) {
	printf("Robot @"); vector2D_print(rb->position, p);
	printf("<%.*f Distance from origin = %.*f", p, rb->angle, p, vector2D_modulo(rb->position));
}
