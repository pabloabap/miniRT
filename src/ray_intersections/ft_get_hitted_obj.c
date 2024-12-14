/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hitted_obj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:33:37 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/07 15:33:39 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/**
 * Retorna el primer objeto cuyo valor de impacto sea positivo de la lista de 
 * intersecciones del rayo.
 * @param i_list Puntero al primer elemento de la lista de intersecciones de 
 * 		un rayo.
 * @return Estructura del objeto `t_oitem` o NULL en caso de no 
 * 		haber impacto.
 */
t_oitem	*ft_get_hitted_obj(t_ray_inters *i_list)
{
	while (i_list && 0 == i_list->hit)
		i_list = i_list->next;
	if (0 != i_list->hit)
		return (i_list->obj);
	else
		return (NULL);
}
