/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inverse_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:18:18 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:18:24 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/mini_rt.h"

static t_matrix	ft_inverse_matrix_builder(t_matrix m);

/* Calculo de la matriz inversa de la matriz `m` recibida como parametro,
 * la matriz debe de der de 4x4.
 */
t_matrix	ft_inverse_matrix(t_matrix *m)
{
	t_matrix	inverse_matrix;

	m->det = ft_matrix_det(*m, 0, 0);
	if (m->det == 0)
		return (ft_identity_matrix(4, 4));
	inverse_matrix = ft_inverse_matrix_builder(ft_matrix_transpos(*m));
	ft_scalar_mult(&inverse_matrix, 1 / m->det, MATRIX);
	return (inverse_matrix);
}

/**
 * Compone la matriz inversa de `m`.
 * @param m Matriz de la que obtener la inversa.
 * @return Matriz inversa de `m`.
 */
static t_matrix	ft_inverse_matrix_builder(t_matrix m)
{
	int			i;
	int			j;
	t_matrix	tmp;
	t_matrix	adj_matrix;

	i = 0;
	j = 0;
	tmp = m;
	while (i < m.rows)
	{
		while (j < m.cols)
		{
			adj_matrix = ft_submatrix(tmp, i, j);
			m.val[i][j] = ft_matrix_det(adj_matrix, 0, 0) \
				* ft_cofactor(i, j);
			j ++;
		}
		i ++;
		j = 0;
	}
	return (m);
}
