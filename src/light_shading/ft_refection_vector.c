//CABECERA
#include "../../include/mini_rt.h"

/**
 * Retorna el resultado de reflejar el vector `in` al rededor
 * del vector `normal`.
 */
t_tuple	ft_reflection_vector(t_tuple in, t_tuple normal)
{
	double	dot;

	ft_vectors_op_check(in, normal);
	dot = ft_dot(in, normal);
	ft_scalar_mult(&normal, dot * 2, VECTOR);
	return (ft_sub_tuples(in, normal));
}
