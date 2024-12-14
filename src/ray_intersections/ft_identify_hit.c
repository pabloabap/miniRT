/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identify_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:20:41 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:20:44 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/** 
 * Retorna 1 si encuentra un punto de interseccion positivo de un rayo
 * en una lista de impactos, o 0 si no y actualiza el valor del atributo hit
 * a 1 del primer impacto positivo más cercano a cero.
 * 
 */
int	ft_identify_hit(t_ray_inters *i_list)
{
	int	hit;

	hit = 0;
	while (i_list && 0 == hit)
	{
		if (i_list->inter_point >= 0)
		{
			hit = 1;
			i_list->hit = hit;
		}
		i_list = i_list->next;
	}
	return (hit);
}
