/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_scalation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:19:01 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:19:06 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/mini_rt.h"

static t_matrix	ft_build_scal_matrix(double x, double y, double z);

/**
 * Escala matrices en el espacio.
 * @param m Matriz a escalar.
 * @param x Unidades de escalado en la coordenada X.
 * @param y Unidades de escalado en la coordenada Y.
 * @param z Unidades de escalado en la coordenada Z.
 * 
 * @return Matriz `m`escalada.
 */
t_matrix	ft_matrix_scalation(t_matrix m, double x, double y, double z)
{
	t_matrix	scal_matrix;

	scal_matrix = ft_build_scal_matrix(x, y, z);
	return (ft_matrix_mult(scal_matrix, m));
}

/**
 * Escalación inversa. Sirve para escalar matrices en el espacio
 * en la dirección opesta a las coordenadas indicadas.
 * @param m Matriz a escalar.
 * @param x Unidades de escalado en la coordenada X.
 * @param y Unidades de escalado en la coordenada Y.
 * @param z Unidades de escalado en la coordenada Z.
 * 
 * @return Matriz de escalación inversa de `m`.
 */
t_matrix	ft_matrix_inverse_scalation(t_matrix m, double x, double y, \
	double z)
{
	t_matrix	scal_matrix;

	scal_matrix = ft_build_scal_matrix(x, y, z);
	scal_matrix = ft_inverse_matrix(&scal_matrix);
	return (ft_matrix_mult(scal_matrix, m));
}

/**
 * Construye de la matriz para realizar la operación de escalado.
 * Se obtiene cambiando los tres primeros elementos de la diagonal de la 
 * matriz identidad por  las unidades `x`, `y` y `z` que queramos escalar.
 */
static t_matrix	ft_build_scal_matrix(double x, double y, double z)
{
	t_matrix	trans_matrix;

	trans_matrix = ft_identity_matrix(4, 4);
	trans_matrix.val[0][0] = x;
	trans_matrix.val[1][1] = y;
	trans_matrix.val[2][2] = z;
	trans_matrix.val[3][3] = 1;
	return (trans_matrix);
}
