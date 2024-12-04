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

/** 
 * Define los atributos inciales del material del objeto. Un color definido por
 * el usuario y características del reflejo de la luz definidas por defecto
 * @param color Entero que representa el código de color del obejto.
 * @return `t_material` con los atributos de color del objeto. * 
 */
t_material	ft_default_material(int color)
{
	t_material	m;

	m.color = color;
	m.ambient = 0;
	m.diffuse = 0.7;
	m.specular = 0.3;
	m.shininess = 200.0;
	return (m);
}

/**
 * Calcula el color final de los objetos de la escena, obtenido de la 
 * combinación del color original del objeto y el color de la luz ambiente. 
 * Primero se normalizan para operarlos y luego se escalan al rango 0-255 para 
 * conseguir el color final.
 * @param obj Puntero al primer elemento de la lista de objetos para iterar y
 * 	calcular sus colores finales.
 * @param ambt Punteor a la estructura `t_ambient` que contine la información
 * de la luz ambiente.
 * @return Nada, actualiza los valores necesarios en cada objeto de la lista 
 * 	mediante punteros.
 */
void	ft_final_material_color(t_oitem *obj, t_ambient *ambt)
{
	t_tuple	mat_color_t;
	t_tuple	ambt_color_t;
	t_tuple	final_color_t;

	while (obj)
	{
		mat_color_t = ft_normalize_color(obj->material.color);
		ambt_color_t = ft_normalize_color(ambt->color);
		final_color_t = ft_mult_tuples(mat_color_t, ambt_color_t);
		obj->material.color = ft_create_trgb(0, final_color_t.x * 255, \
			final_color_t.y * 255, final_color_t.z * 255);
		obj->material.ambient = ambt->ratio;
		obj = obj->next;
	}
}
