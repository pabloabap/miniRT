#include "../include/mini_rt.h"

/**
 * Imprime tupla recibida como parámetro para debugear
 */
void	ft_print_tuple(t_tuple t)
{
	printf("X: %f, Y: %f, Z: %f, W: %f\n", t.x, t.y, t.z, t.w);
}