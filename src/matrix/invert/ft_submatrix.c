/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_submatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:18:43 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:18:46 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/mini_rt.h"

/**
 * De la matriz `m` y el número de fila (`row`) y columna (`col`) a eliminar,
 * retorna la submatriz resultante.
 */
t_matrix	ft_submatrix(t_matrix m, int row, int col)
{
	int			i;
	int			j;
	t_matrix	subm;

	i = 0;
	j = 0;
	subm = ft_build_matrix(m.rows - 1, m.cols - 1);
	while (i < subm.rows)
	{
		while (j < subm.cols)
		{
			subm.val[i][j] = m.val[i + (i >= row)][j + (j >= col)];
			j ++;
		}
		j = 0;
		i ++;
	}
	return (subm);
}
