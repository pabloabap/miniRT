/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_shearing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:19:11 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:19:15 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/mini_rt.h"

/**
 * Permite inclinación inversa de matrices en base a otros ejes.
 * @param m Matriz sobre la que aplicar la función.
 * @param axis Eje que va a moverse.
 * @param over_axis Eje base, en proporción al cual se va a moder
 * 		`axis`.
 * @param val Unidades de inclinación a aplicar.
 * 
 * @return Matriz `m` con la inclinación aplicada.
 */
t_matrix	ft_matrix_shearing(t_matrix m, int axis, int over_axis, double val)
{
	t_matrix	shearing_matrix;

	shearing_matrix = ft_identity_matrix(4, 4);
	shearing_matrix.val[axis][over_axis] = val;
	shearing_matrix = ft_matrix_mult(shearing_matrix, m);
	return (shearing_matrix);
}

/**
 * Permite inclinación inversa de matrices en base a otros ejes.
 * @param m Matriz sobre la que aplicar la función.
 * @param axis Eje que va a moverse.
 * @param over_axis Eje base, en proporción al cual se va a mover
 * 		`axis`.
 * @param val Unidades de inclinación a aplicar.
 * 
 * @return Matriz `m` con la inclinación aplicada.
 */
t_matrix	ft_matrix_inverse_shearing(t_matrix m, int axis, int over_axis, \
	double val)
{
	t_matrix	shearing_matrix;

	shearing_matrix = ft_identity_matrix(4, 4);
	shearing_matrix.val[axis][over_axis] = val;
	shearing_matrix = ft_inverse_matrix(&shearing_matrix);
	shearing_matrix = ft_matrix_mult(shearing_matrix, m);
	return (shearing_matrix);
}
