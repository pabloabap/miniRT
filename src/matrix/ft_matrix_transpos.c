/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_transpos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:17:50 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:17:53 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/** 
 * Traspone la matriz recibida como parametro.
 * @return Nueva matriz con la traspuesta de `m`.
 */
t_matrix	ft_matrix_transpos(t_matrix m)
{
	int			i;
	int			j;
	t_matrix	tmp_matrix;

	tmp_matrix = ft_build_matrix(m.cols, m.rows);
	i = 0;
	j = 0;
	while (i < m.rows)
	{
		while (j < m.cols)
		{
			tmp_matrix.val[j][i] = m.val[i][j];
			j++;
		}
		j = 0;
		i ++;
	}
	return (tmp_matrix);
}
