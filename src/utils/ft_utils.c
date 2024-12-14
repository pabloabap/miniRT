/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:28:53 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:28:56 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/**
 * Asigna id disponible al elemento que la invoca;
 * `id`es la variable estática que almacena el id dispoible para la siguiente
 * llamada.
 */
int	ft_obj_id_assignment(void)
{
	int			available_id;
	static int	id = 0;

	available_id = id;
	id ++;
	return (available_id);
}

/**
 * Conversor de radianes a grados.
 */
double	ft_rad_to_deg(double radians)
{
	return (radians * (180 / M_PI));
}
