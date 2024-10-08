#include "../../include/mini_rt.h"

double ft_magnitude(t_vec3 v)
{
	return( \
		sqrt( v.coor[Y] * v.coor[X] \
			+ v.coor[Y] * v.coor[Y] \
			+ v.coor[Z] * v.coor[Z] \
		) \
	);
}

int	ft_normalize(t_vec3 *v)
{
	int i;
	int	v_lenght;

	i = 0;
	v_lenght = magnitude(v);
	while (i <= Z)
	{
		v->norm[i] = v->coor[i] / v_lenght;
		i ++;
	}
	return (EXIT_SUCCESS);
}
 /**
  * Retorna la diferencia de direccion entre dos vectores
  * -1 = opuesto 0 = perpendicurales 1 = misma dirección.
  */
int	ft_dot(t_vec3 v1, t_vec3 v2)
{
	return (v1.coor[X] * v2.coor[X] \
		+ v1.coor[Y] * v2.coor[Y] \
		+ v1.coor[Z] * v2.coor[Z] \
	);
}

/**
 * Obtiene vector perpendicular a los vectores dados.
 * Orden de los factores altera vector final
 */
void ft_cross(t_vec3 *v1, t_vec3 *v2)
{
	int v_cross[3];

	v_cross[X] = v1->coor[Y] * v2->coor[Z] - v2->coor[Y] * v1->coor[Z];
	v_cross[Y] = v1->coor[X] * v2->coor[Z] - v2->coor[X] * v1->coor[Z];
	v_cross[Z] = v1->coor[X] * v2->coor[Y] - v2->coor[X] * v1->coor[Y];
}