/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_inters_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:20:03 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/07 15:34:21 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static int	ft_build_new_inters(t_ray_inters **new, double inter_point, \
	t_oitem *obj);
static void	ft_i_list_update(t_ray_inters **i_list, t_ray_inters *tmp, \
	t_ray_inters *new);

/**
 * Añade en orden ascendente una nueva estructura a la lista de intersecciones
 * en base al valor de `inter_point`. Esto permite obtener el objeto que
 * recibe el primer impacto mayor a 0 (impacto que se mostrará en la escena).
 * @param i_list Doble puntero al primer elemento de la lista para
 * 	recorrerla y actualizar el puntero en caso de necesitarlo.
 * @param inter_point Punto de intersección del rayo y el objeto.
 * @param obj Puntero al objeto que ha sido impactado.
 * @return Entero con el resultado de salida de la función.
 */
int	ft_add_inters_sorted(t_ray_inters **i_list, double inter_point, \
	t_oitem *obj)
{
	t_ray_inters	*tmp;
	t_ray_inters	*new;

	ft_build_new_inters(&new, inter_point, obj);
	if (*i_list == NULL)
		*i_list = new;
	else
	{
		tmp = *i_list;
		while (tmp->next && inter_point > tmp->inter_point)
			tmp = tmp->next;
		ft_i_list_update(i_list, tmp, new);
	}
	return (EXIT_SUCCESS);
}

/**
 * Constructor de una nueva estructura `t_ray_inters`para incluirla en la
 * lista de intersecciones.
 * @param new Doble puntero a `t_ray_inters` para darle contenido.
 * @param inter_point Punto de intersección del rayo y el objeto.
 * @param obj Puntero al objeto que ha sido impactado.
 * @return Entero con el resultado de salida de la función.
 */
static int	ft_build_new_inters(t_ray_inters **new, double inter_point, \
	t_oitem *obj)
{
	*new = (t_ray_inters *)malloc(sizeof(t_ray_inters));
	if (NULL == new)
		return (EXIT_FAILURE);
	(*new)->inter_point = inter_point;
	(*new)->obj = obj;
	(*new)->hit = 0;
	(*new)->prev = NULL;
	(*new)->next = NULL;
	return (EXIT_SUCCESS);
}

/**
 * Actualiza el contenido de la lista de intersecciones.
 * @param i_list Doble puntero al primer elemento de la lista para
 * 	recorrer la lista y actualizar el puntero en caso de necesitarlo.
 * @param tmp Puntero al elemento de la lista inmediatamente mayor
 * 	al `new` elemento que se quiere añadir o último elemento de la
 * 	lista si no hay elemento mayor.
 * @param new Puntero al nuevo elemento que se quiere añadir a la lista.
 */
static void	ft_i_list_update(t_ray_inters **i_list, t_ray_inters *tmp, \
	t_ray_inters *new)
{
	if (!tmp->next && new->inter_point > tmp->inter_point)
	{
		new->prev = tmp;
		tmp->next = new;
	}
	else
	{
		new->prev = tmp->prev;
		new->next = tmp;
		if (tmp->prev)
			tmp->prev->next = new;
		tmp->prev = new;
		if (tmp == *i_list)
			*i_list = new;
	}
}
