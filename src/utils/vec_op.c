/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:05:56 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/07 19:05:58 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/**
 * Obtiene la magnitud del vector `v`.
 * @return Magnitud del vector `v`.
 */
double	ft_magnitude(t_tuple v)
{
	ft_vectors_op_check(v, v);
	return (\
		sqrt(v.x * v.x \
			+ v.y * v.y \
			+ v.z * v.z \
			+ v.w * v.w \
		) \
	);
}

/**
 * Normailiza un vector.
 * @return Actualiza el vector al vector normalizado.
 */
t_tuple	ft_normalize(t_tuple v)
{
	double	v_lenght;

	ft_vectors_op_check(v, v);
	v_lenght = ft_magnitude(v);
	if (0 == v_lenght)
		v_lenght = __DBL_EPSILON__;
	v.x = v.x / v_lenght;
	v.y = v.y / v_lenght;
	v.z = v.z / v_lenght;
	v.w = v.w / v_lenght;
	return (v);
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
	v_cross.x = v1.y * v2.z - v1.z * v2.y;
	v_cross.y = v1.z * v2.x - v1.x * v2.z;
	v_cross.z = v1.x * v2.y - v1.y * v2.x;
	v_cross.w = VECTOR;
	return (v_cross);
}
