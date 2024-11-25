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

static int	ft_final_material_color(int mat_color, int ambt_color);

/** Pendiente de completar. Son atributos de un objeto
 * para calcular como le afecta la luz.
 */
t_material	ft_default_material(int color, t_ambient *ambt)
{
	t_material	m;

	m.color = ft_final_material_color(color, ambt->color);
	m.ambient = ambt->ratio;
	m.diffuse = 0.7;
	m.specular = 0.3;
	m.shininess = 200.0;
	return (m);
}

/**
 * Calcula el color final de un objeto, obtenido de la combinación del
 * color original del objeto y el color de la luz ambiente. Primero se 
 * normalizan para operarlos y luego se escalan al rango 0-255 para conseguir
 * el color final.
 * @param mat_color Entero con el código de color original del material.
 * @param ambt_color Entero con el código de color de la luz ambiente.
 * @return Entero con el color final del material. 
 */
static int	ft_final_material_color(int mat_color, int ambt_color)
{
	t_tuple	mat_color_t;
	t_tuple	ambt_color_t;
	t_tuple	final_color_t;

	mat_color_t = ft_normalize_color(mat_color);
	ambt_color_t = ft_normalize_color(ambt_color);
	final_color_t = ft_mult_tuples(mat_color_t, ambt_color_t);
	return (ft_create_trgb(0, final_color_t.x * 255, final_color_t.y * 255, \
		final_color_t.z * 255));
}
