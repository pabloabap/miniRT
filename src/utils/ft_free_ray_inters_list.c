/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ray_inters_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:06:45 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/07 19:07:28 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/** 
 * Libera la memoria dinamica alojada para almacenar la lista de intersecciones
 * de un rayo.
 * @param list_head Lista de intersecciones de un rayo.
 * @return Nada, libera la memoria a traves del puntero.
 */
void	ft_free_ray_inters_list(t_ray_inters *list_head)
{
	t_ray_inters	*tmp;

	tmp = list_head;
	while (tmp)
	{
		tmp = tmp->next;
		free(list_head);
		list_head = tmp;
	}
}
