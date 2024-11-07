/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:29:32 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:29:35 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

void	ft_vectors_op_check(t_tuple a, t_tuple b)
{
	if (a.w != VECTOR || b.w != VECTOR)
	{
		ft_putstr_fd("ERROR - No se pueden operar elementos distintos ", 2);
		ft_putendl_fd(" a vector en una operación vectorial.", 2);
		exit (1);
	}
}

void	ft_tuples_check(int w)
{
	if (w > 1 && w != COLOR + COLOR)
	{
		ft_putendl_fd("ERROR - Suma de dos puntos, operación invalida.", 2);
		exit (1);
	}
	else if (w < 0)
	{
		ft_putstr_fd("ERROR - Resta de punto a un vector, operación", 2);
		ft_putendl_fd(" invalida. Prueba la operacion opuesta.", 2);
		exit (1);
	}
}

void	ft_matrix_det_check(t_matrix m)
{
	if (m.rows != m.cols)
	{
		ft_putstr_fd("ERROR - No se puede calcular determinante,", 2);
		ft_putendl_fd(" matriz no cuadrada.", 2);
		exit (1);
	}
}

void	ft_matrix_mult_check(t_matrix m1, t_matrix m2)
{
	if (m1.cols != m2.rows)
	{
		ft_putstr_fd("ERROR - El número de filas de la primera matriz tiene", \
			2);
		ft_putendl_fd(" que ser igual al número de columnas de la segunda.", \
			2);
		exit (1);
	}
}

void	ft_matrix_to_tuple_check(t_matrix m)
{
	if ((m.rows != 1 && m.cols != 4 && m.val[0][4] > 1) \
		&& (m.rows != 4 && m.cols != 1 && m.val[4][1] > 1))
	{
		ft_putstr_fd("ERROR - La matriz tiene que ser de 1x4 o de 4x1", 2);
		ft_putendl_fd(" para poder transformala el tupla.", 2);
		exit (1);
	}
}
