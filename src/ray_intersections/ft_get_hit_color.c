/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hit_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:20:20 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:20:22 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/**
 * Retorna el color del punto impactado de la lista de intersecciones del rayo.
 * @param i_list Puntero al primer elemento de la lista de intersecciones de 
 * 		un rayo.
 * @return `int`con el codigo de color del objeto impactado.
 */
int	ft_get_hit_color(t_ray_inters *i_list)
{
	while (i_list && 0 == i_list->hit)
		i_list = i_list->next;
	if (0 != i_list->hit)
		return (i_list->obj->material.color);
	return (0);
}
