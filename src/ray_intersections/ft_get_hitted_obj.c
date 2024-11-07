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
 * @param o_list Lista de objetos de la escena para obtener el color del objeto
 * 		impactado.
 * @return Estructura del objeto `t_oitem` o NULL en caso de no 
 * 		haber impacto.
 */
t_oitem	*ft_get_hitted_obj(t_ray_inters *i_list, t_oitem *o_list)
{
	while (i_list && 0 == i_list->hit)
		i_list = i_list->next;
	if (0 != i_list->hit)
	{
		while (i_list->obj_id != o_list->obj_id)
			o_list = o_list->next;
		return (o_list);
	}
	return (NULL);
}
