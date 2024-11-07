/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cofactor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:18:09 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:18:13 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/mini_rt.h"

/**
 * Aplica los cambios de signo de cofactor en el 
 * calculo de determinates de una matriz.
 */
int	ft_cofactor(int row, int col)
{
	if (0 == ((row + col) % 2))
		return (1);
	else
		return (-1);
}
