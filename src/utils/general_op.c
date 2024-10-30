// Negar tuplas: Vector opuesto.

#include "../../include/mini_rt.h"

/**
 * Suma de elementos tipo tupla (punto o vector). 
 * @return tupla resultante de la operación.
*/
t_tuple	ft_add_tuples(t_tuple a, t_tuple b)
{
	ft_tuples_check(a.w + b.w);
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return (a);
}

/**
 * Resta de elementos tipo tupla (punto o vector). 
 * @return tupla resultante de la operación.
*/
t_tuple	ft_sub_tuples(t_tuple a, t_tuple b)
{
	ft_tuples_check(a.w - b.w);
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	a.w -= b.w;
	return (a);
}

/**
 * Punto o vector opuesto al recibido. 
 * @return tupla resultante de la operación.
*/
t_tuple	ft_negate_tuple(t_tuple a)
{
	a.x *= -1;
	a.y *= -1;
	a.z *= -1;
	return (a);
}

/**
 * Multiplicando colores se obtiene un nuevo color
 * con la mezcla. 
 * @return tupla resultante de la operación.
 */
t_tuple ft_mult_tuples(t_tuple a, t_tuple b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return (a);
}

/**
 * Escalar `e` (punto, vector, color o matriz) por `s`. Como la operacion es la
 * misma para todos los elementos geométricos `elem_type` informa del 
 * elemento recibido para castearlo según corresponda.
 * `elem` se actualiza con el valor de la operación.
*/
void ft_scalar_mult (void *e, double s, int e_type)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (e_type == MATRIX)
	{
		while (i < ((t_matrix *)e)->rows)
		{
			while (j < ((t_matrix *)e)->cols)
			{
				(*(t_matrix *)e).val[i][j] *= s;
				j ++;
			}
			i ++;
			j = 0;
		}	
	}
	else if (e_type == POINT || e_type == VECTOR || e_type == COLOR)
	{
		((t_tuple *)e)->x *= s;
		((t_tuple *)e)->y *= s;
		((t_tuple *)e)->z *= s;
	}
}