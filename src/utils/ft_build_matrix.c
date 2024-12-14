/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:27:27 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:27:29 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/**
 * Creación de una estructura matriz de dimension rows x cols.
 * @param rows Filas utilizadas de la matriz.
 * @param cols Columnas utilizadas de la matriz.
 * @return Estructura matriz con valores a cero.
*/
t_matrix	ft_build_matrix(int rows, int cols)
{
	int			i;
	int			j;
	t_matrix	matrix;

	i = 0;
	j = 0;
	matrix.rows = rows;
	matrix.cols = cols;
	matrix.det = 0;
	while (i < 4)
	{
		while (j < 4)
			matrix.val[i][j++] = 0;
		j = 0;
		i ++;
	}
	return (matrix);
}
