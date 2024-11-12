/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_material.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:29:17 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/12 23:14:31 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/** Pendiente de completar. Son atributos de un objeto
 * para calcular como le afecta la luz.
 */
t_material	ft_default_material(int color)
{
	t_material	m;

	m.color = color;
	m.ambient = 0.5;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 1.0;
	return (m);
}

/** Modifica las propiedades de la propiedad `material` de una
 * estructure `t_oitem` a traves de punteros.
 * @param o_list Puntero al primer elemento de una lista de objetos.
 * @param obj_id ID del objeto al que modificar la propiedad.
 * @param property Elemento de la enum `t_light_types` que se quiere modificar.
 * @param value Valor que se quiere dar a la propedad.
 */
void	ft_modify_material_property(t_oitem *o_list, int obj_id, \
	int property, double value)
{
	while (o_list && o_list->obj_id != obj_id)
		o_list = o_list->next;
	if (o_list)
	{
		if (EFECTIVE_COLOR == property)
			o_list->material.color = (int)value;
		if (AMBIENT == property)
			o_list->material.ambient = value;
		if (DIFFUSE == property)
			o_list->material.diffuse = value;
		if (SPECULAR == property)
			o_list->material.specular = value;
		if (SHININESS == property)
			o_list->material.shininess = value;
	}
}
