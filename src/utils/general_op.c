// Negar tuplas: Vector opuesto.

#include "../../include/mini_rt.h"

/**
 * Suma de elementos tipo tupla (punto o vector). 
 * `a` se actualiza con el valor de la operación.
*/
void	ft_add_tuples(t_tuple *a, t_tuple b)
{
	ft_tuples_check(a->w + b.w);
	a->x += b.x;
	a->y += b.y;
	a->z += b.z;
	a->w += b.w;
}

/**
 * Resta de elementos tipo tupla (punto o vector). 
 * `a` se actualiza con el valor de la operación.
*/
void	ft_sub_tuples(t_tuple *a, t_tuple b)
{
	ft_tuples_check(a->w - b.w);
	a->x += b.x;
	a->y += b.y;
	a->z += b.z;
	a->w += b.w;
}

/**
 * Punto o vector opueto al recibido. 
 * `a` se actualiza con el valor de la operación.
*/
void	ft_negate_tuple(t_tuple *a)
{
	a->x *= -1;
	a->y *= -1;
	a->z *= -1;
}

/**
 * Multiplicando colores se obtiene un nuevo color
 * con la mezcla. `a` se actualiza con el valor de la operación
 */
void ft_mult_tuples(t_tuple *a, t_tuple b)
{
	a->x *= b.x;
	a->y *= b.y;
	a->z *= b.z;
	a->w *= b.w;
}

/**
 * Escalar `elem` (punto, vector o matrz) por `s`. Como la operacion es la
 * misma para todos los elementos geométricos `elem_type` informa del 
 * elemento recibido para castearlo según corresponda.
 * `elem` se actualiza con el valor de la operación.
*/
void ft_scalar_mult (void *elem, double s, int elem_type)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (elem_type == MATRIX)
	{
		while (i < ((t_matrix *)elem)->rows)
		{
			while (j < ((t_matrix *)elem)->cols)
			{
				(*(t_matrix *)elem).val[i][j] *= s;
				j ++;
			}
			i ++;
			j = 0;
		}	
	}
	else if (elem_type == POINT || elem_type == VECTOR)
	{
		while (i < 3)
			((int *)elem)[i] *= s;
	}
}