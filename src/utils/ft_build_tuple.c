/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_tuple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:27:48 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:27:50 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/**
 * Creación de tupla a partir de parametros dados.
 * @return tupla construida.
 */
t_tuple	ft_build_tuple(double x, double y, double z, int w)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = w;
	return (t);
}
