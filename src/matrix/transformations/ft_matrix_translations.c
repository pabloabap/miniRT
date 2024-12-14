/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_translations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:19:24 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:19:30 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/mini_rt.h"

static t_matrix	ft_build_trans_matrix(double x, double y, double z);

/**
 * Traslada matrices en el espacio.
 * En caso de que `m` represente un vector (elemento 4,4 de la matriz = 0)
 * la operación será ignorada. Un vector representa una dirección de 
 * desplazamiento, moverlo en el espacio no varía su dirección.
 * @param m Matriz a trasladar.
 * @param x Unidades de traslando en la coordenada X.
 * @param y Unidades de traslando en la coordenada Y.
 * @param z Unidades de traslando en la coordenada Z.
 * 
 * @return Matriz `m`trasladada.
 */
t_matrix	ft_matrix_translation(t_matrix m, double x, double y, double z)
{
	t_matrix	final_matrix;
	t_matrix	trans_matrix;

	trans_matrix = ft_build_trans_matrix(x, y, z);
	final_matrix = ft_matrix_mult(trans_matrix, m);
	return (final_matrix);
}

/**
 * Traslación inversa. Sirve para mover matrices en el espacio
 * en la dirección opesta a las coordenadas indicadas.
 * En caso de que `m` represente un vector (elemento 4,4 de la matriz = 0)
 * la operacion será ignorada. Un vector representa una dirección de 
 * desplazamiento, moverlo en el espacio no varía su dirección.
 * @param m Matriz a trasladar.
 * @param x Unidades de traslando en la coordenada X.
 * @param y Unidades de traslando en la coordenada Y.
 * @param z Unidades de traslando en la coordenada Z.
 * 
 * @return Matriz `m` con la traslación inversa aplicada.
 */
t_matrix	ft_matrix_inverse_translation(t_matrix m, double x, double y, \
	double z)
{
	t_matrix	final_matrix;
	t_matrix	trans_matrix;

	trans_matrix = ft_build_trans_matrix(x, y, z);
	trans_matrix = ft_inverse_matrix(&trans_matrix);
	final_matrix = ft_matrix_mult(trans_matrix, m);
	return (final_matrix);
}

/**
 * Construcción de la matriz para realizar la operación de traslación.
 * Se obtiene añadiendo a la matriz identidad las unidades `x`, `y` y `z`
 * que queramos desplazar un punto en las tres primeras posiciones de la 
 * última columna de la matriz respectivamente.
 */
static t_matrix	ft_build_trans_matrix(double x, double y, double z)
{
	t_matrix	trans_matrix;

	trans_matrix = ft_identity_matrix(4, 4);
	trans_matrix.val[0][3] = x;
	trans_matrix.val[1][3] = y;
	trans_matrix.val[2][3] = z;
	trans_matrix.val[3][3] = 1;
	return (trans_matrix);
}
