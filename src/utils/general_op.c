#include "../../include/mini_rt.h"

void ft_add(double a[4], double b[4])
{
	double	c[4];

	c[X] = a[X] + b[X];
	c[Y] = a[Y] + b[Y];
	c[Z] = a[Z] + b[Z];
	//c[W] = a[W] + b[W];
}

void ft_sub(double a[4], double b[4])
{
	double	c[4];

	c[X] = a[X] - b[X];
	c[Y] = a[Y] - b[Y];
	c[Z] = a[Z] - b[Z];
	//c[W] = a[W] + b[W];
}

/**
 * Multiplicando colores se obtiene un nuevo color
 * con la mezcla.
 */
void ft_mult(double a[4], double b[4])
{
	double	c[4];

	c[X] = a[X] * b[X];
	c[Y] = a[Y] * b[Y];
	c[Z] = a[Z] * b[Z];
	//c[W] = a[W] + b[W];

}