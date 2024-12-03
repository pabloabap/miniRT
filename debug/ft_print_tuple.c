/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tuple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:46:40 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/12/03 14:46:59 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

/**
 * Imprime tupla recibida como parámetro para debugear
 */
void	ft_print_tuple(t_tuple t)
{
	printf("X: %f, Y: %f, Z: %f, W: %f\n", t.x, t.y, t.z, t.w);
}
