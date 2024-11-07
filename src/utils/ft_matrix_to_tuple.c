/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_to_tuple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:29:09 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:29:12 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/**
 * Convierte tuplas en matrices para poder hacer operaciones
 * de matries con ellas. Es util para aplicar multiples transorfmaciones
 * a la vez.
 */
t_tuple	ft_matrix_to_tuple(t_matrix m)
{
	t_tuple	t;

	if (m.rows == 1 && m.cols == 4)
	{
		t.x = m.val[0][0];
		t.y = m.val[0][1];
		t.z = m.val[0][2];
		t.w = m.val[0][3];
	}
	else if (m.rows == 4 && m.cols == 1)
	{
		t.x = m.val[0][0];
		t.y = m.val[1][0];
		t.z = m.val[2][0];
		t.w = m.val[3][0];
	}
	return (t);
}
