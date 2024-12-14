/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_view_transform.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:38:24 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/09 23:38:29 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/mini_rt.h"

static t_matrix	ft_tuple_to_matrix_row(t_tuple tuple, t_matrix matrix, \
	int row);
static t_matrix	ft_build_orientation_matrix(t_tuple from_p, t_tuple to_p, \
	t_tuple up_v);

/**
 * Matriz para ajustar el punto de vista de la escena.
 * @param from_p Punto donde situar la camara.
 * @param to_p Punto de la escena al que se quiere mirar.
 * @param up_v Vector que indica la direccion hacia arriba.
 * @return Matriz con las transformaciones necesarias para ajustar el punto 
 * de vista de la escena.
 */
t_matrix	ft_matrix_view_transform(t_tuple from_p, t_tuple to_p, \
	t_tuple up_v)
{
	t_matrix	view_transform;

	ft_matrix_view_transform_check(from_p, to_p, up_v);
	view_transform = ft_build_orientation_matrix(from_p, to_p, up_v);
	return (ft_matrix_mult(view_transform, \
		ft_matrix_translation(ft_identity_matrix(4, 4), -from_p.x, -from_p.y, \
		-from_p.z)));
}

/** Constructuor de la matriz de orientacion.
 * @param from_p Punto donde situar la camara.
 * @param to_p Punto de la escena al que se quiere mirar.
 * @param up_v Vector que indica la direccion hacia arriba.
 * @return Matriz de orientacion.
 */
static t_matrix	ft_build_orientation_matrix(\
	t_tuple from_p, t_tuple to_p, t_tuple up_v)
{
	t_tuple		forward_v;
	t_tuple		left_v;
	t_tuple		true_up_v;
	t_matrix	orient_matrix;

	forward_v = ft_normalize(ft_sub_tuples(to_p, from_p));
	left_v = ft_cross(forward_v, ft_normalize(up_v));
	true_up_v = ft_cross(left_v, forward_v);
	orient_matrix = ft_identity_matrix(4, 4);
	orient_matrix = ft_tuple_to_matrix_row(left_v, orient_matrix, 0);
	orient_matrix = ft_tuple_to_matrix_row(true_up_v, orient_matrix, 1);
	orient_matrix = ft_tuple_to_matrix_row(ft_negate_tuple(forward_v), \
		orient_matrix, 2);
	ft_matrix_det(orient_matrix, 0, 0);
	return (orient_matrix);
}

/**
 * Sustituye los elementos de las columnas 0, 1, 2 y 3 de la `row` en la 
 * `matriz` indicada por los elementos `x`, `y` y `z` de `tuple`.
 * @param tuple Punto/Vector que se quiere incluir en la fila de la matriz.
 * @param matrix Matriz original.
 * @param row Numero de fila a modificar (el indice empieza en cero).
 * @return Matriz con la transformacion aplicada. 
 */
static t_matrix	ft_tuple_to_matrix_row(t_tuple tuple, t_matrix matrix, int row)
{
	t_matrix	new_matrix;

	new_matrix = matrix;
	new_matrix.val[row][0] = tuple.x;
	new_matrix.val[row][1] = tuple.y;
	new_matrix.val[row][2] = tuple.z;
	new_matrix.val[row][3] = 0;
	return (new_matrix);
}
