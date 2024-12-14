/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:45:06 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/12/03 14:45:42 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

/** Imprime los valores de las estructuras de una lista de intersecciones */
void	ft_print_i_list(t_ray_inters *i_list)
{
	while (i_list)
	{
		printf("HIT: %i, INTER_POINT: %f, OBJ: %p, PREV: %p, NEXT: %p\n", \
		i_list->hit, i_list->inter_point, i_list->obj, i_list->prev, \
			i_list->next);
		i_list = i_list->next;
	}
}
