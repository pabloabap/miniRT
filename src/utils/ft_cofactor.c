#include "../../include/mini_rt.h"

/* 
 * Aplica los cambios de signo de cofactor en el 
 * calculo de determinates de una matriz.
*/
int	ft_cofactor(int row, int col)
{
	if (0 == ((row + col) % 2))
		return (1);
	else
		return (-1);
}
