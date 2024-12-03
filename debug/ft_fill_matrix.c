/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:44:08 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/12/03 14:45:01 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

void	ft_fill_matrix(t_matrix *m, char *arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < m->rows)
	{
		while (j < m->cols)
		{
			(*m).val[i][j] = ft_atoi(arr);
			if ((j + 1) < m->cols)
				arr = ft_strchr(arr, ',') + 1;
			j++;
		}
		arr = ft_strchr(arr, ';') + 1;
		i ++;
		j = 0;
	}
}
