#include "../../include/mini_rt.h"

/**
 * Obtiene la magnitud del vector `v`.
 * @return Magnitud del vector `v`.
 */
double ft_magnitude(t_tuple v)
{
	ft_vectors_op_check(v, v);
	return( \
		sqrt( v.x * v.x \
			+ v.y * v.y \
			+ v.z * v.z \
		) \
	);
}

/**
 * Normailiza un vector.
 * @return Actualiza el vector al vector normalizado.
 */
void	ft_normalize(t_tuple *v)
{
	int	v_lenght;

	ft_vectors_op_check(*v, *v);
	v_lenght = ft_magnitude(*v);
	v->x = v->x / v_lenght;
	v->y = v->y / v_lenght;
	v->x = v->z / v_lenght;
}

/**
 * Retorna la diferencia de direccion entre dos vectores
 * -1 = opuesto, 0 = perpendicurales, 1 = misma dirección.
 * @return dot product.
 */
double	ft_dot(t_tuple v1, t_tuple v2)
{
	ft_vectors_op_check(v1, v2);
	return (v1.x * v2.x \
		+ v1.y * v2.y \
		+ v1.z * v2.z \
	);
}

/**
 * Obtiene vector perpendicular a los vectores dados.
 * Orden de los factores altera vector final.
 * @return vector perpendicular.
 */
t_tuple	ft_cross(t_tuple v1, t_tuple v2)
{
	t_tuple	v_cross;

	ft_vectors_op_check(v1, v2);	
	v_cross.x = v1.y * v2.z - v2.y * v1.z;
	v_cross.y = v1.x * v2.z - v2.x * v1.z;
	v_cross.z = v1.x * v2.y - v2.x * v1.y;
	return(v_cross);
}