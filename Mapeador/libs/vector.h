/* vector.* files handle basic operations with vectors
* Esto en C++ no pasaba, vamos a ver, si me dejaran usar clases lo solucionaba con clase
*/

#ifndef VECTORH // Checks if this header is included twice. Only lets defining once
#define VECTORH

typedef struct _vector2D vector2D;

struct _vector2D
{
	double x, y;
};

/* Basic operations */
vector2D vector2D_add(const vector2D *, const vector2D *);
vector2D vector2D_substract(const vector2D * vector1, const vector2D * vector2);
vector2D vector2D_productByScalar(const vector2D * vector, double lambda);

double vector2D_scalarVectProduct(const vector2D * vector1, const vector2D * vector2);
double vector2D_modulo(const vector2D * vector);
double vector2D_angle(const vector2D * vector1, const vector2D * vector2);

/* A bit more advanced operations*/
vector2D vector2D_rotate(const vector2D * vector, double angleRad);
vector2D vector2D_normalize(const vector2D * vector);

/* User Interface functions */
void vector2D_print(const vector2D * vector, unsigned char precision);
vector2D vector2D_scanf_s(void);

/* typedef struct vector3D
{
	double x, y, z;
}; */ // Unnused

#endif // !VECTORH
