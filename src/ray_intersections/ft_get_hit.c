/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:20:11 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:20:14 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/** 
 * Retorna el elemento impactado de la lista de intersecciones del rayo,
 * es decir, la primera interseccion mayor a 0.
 * @param i_list Puntero al primer elemento de la lista de intersecciones 
 * 	de un rayo.
 * @return Elemento de la lista que recibe el primer impacto o `NULL` en caso
 *  de que el rayo no impacte en un objeto. 
 */
t_ray_inters	*ft_get_hit(t_ray_inters *i_list)
{
	while (i_list && 0 == i_list->hit)
		i_list = i_list->next;
	if (NULL == i_list || 0 == i_list->hit)
		return (NULL);
	return (i_list);
}
