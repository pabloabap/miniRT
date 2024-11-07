/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identity_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:17:06 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:17:08 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/**
 * Devuelve una matriz identidad con las `rows` y `cols` indicadas.
 */
t_matrix	ft_identity_matrix(int rows, int cols)
{
	int				i;
	int				j;
	t_matrix		matrix;

	i = 0;
	j = 0;
	matrix.rows = rows;
	matrix.cols = cols;
	matrix.det = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (i == j)
				matrix.val[i][j++] = 1;
			else
				matrix.val[i][j++] = 0;
		}
		j = 0;
		i ++;
	}
	return (matrix);
}
