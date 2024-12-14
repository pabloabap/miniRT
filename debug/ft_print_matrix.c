/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:45:50 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/12/03 14:46:01 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

void	ft_print_matrix(t_matrix m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < m.rows)
	{
		while (j < m.cols)
		{
			printf("%02f,", m.val[i][j]);
			j ++;
		}
		printf ("\n");
		i ++;
		j = 0;
	}
}
