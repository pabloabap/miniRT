/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_item_to_inters_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:08:04 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/07 15:11:28 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static void	ft_fill_inter(t_inters *inter);

/**
 * Anade una nueva estructura a la lista de intersecciones.
 * @param inter_list Doble puntero a la lista de intersecciones.
 * Necesario para actualizar su valor en caso de que no exisa valor
 * anterior.
 * @return Resultado de la ejecucion para detectar si hay errores
 * al reservar espacio de memoria dinamica.
 */
int	ft_add_item_to_inters_list(t_inters **inter_list)
{
	t_inters	*tmp;
	t_inters	*new;

	tmp = *inter_list;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (NULL == *inter_list)
	{
		*inter_list = (t_inters *)malloc(sizeof(t_inters));
		if (NULL == *inter_list)
			return (EXIT_FAILURE);
		ft_fill_inter(*inter_list);
	}
	else if (tmp->r_i)
	{
		new = (t_inters *)malloc(sizeof(t_inters));
		if (NULL == new)
			return (EXIT_FAILURE);
		else
		{
			tmp->next = new;
			ft_fill_inter(new);
		}
	}
	return (EXIT_SUCCESS);
}

/**
 * Rellena una estructura de interseccion con los valores por defecto.
 */
static void	ft_fill_inter(t_inters *inter)
{
	inter->r_i = NULL;
	inter->next = NULL;
}
