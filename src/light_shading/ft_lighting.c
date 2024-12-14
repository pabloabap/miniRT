/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lighting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:16:25 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/12/12 01:12:45 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static int		ft_final_color(t_tuple ambt, t_tuple diff, t_tuple spec, \
	double color);
static void		ft_default_light_values(t_tuple *light_types, \
	t_material material, t_point_light light);
static void		ft_specular_reflection(t_point_light light, \
	t_tuple	*specular_light, double reflect_dot_eye, t_material material);

/** 
 * Funcion de alumbrado del modelo de reflexión de Phong
 * @param	material atributo de las estructuras `t_oitem` con información de 
 * 	color y luminosidad del objeto
 * @param	light Estructura `t_point_light` con información de la ubicación y 
 * 	el ratio de brillo de de un punto de luz.
 * @param	point Punto de impacto del rayo con el objeto.
 * @param	eyev Vector ojo. Vector desde el punto de impacto a la ubicación 
 * 	del punto de vista.
 * @param	normalv Vector normal, perpendicular al punto de impacto en el 
 * 	objeto.
 * @return Retornar el color con los ratios de intensidad aplicados del punto
 *  de impacto.
 */
int	ft_lighting(t_pre_comp comps, t_point_light light, t_tuple *inters_vecs, \
	int is_shadowed)
{
	t_tuple		light_types[4];
	double		light_dot_normal;
	double		reflect_dot_eye;
	t_material	material;
	t_tuple		point;

	material = comps.obj->material;
	point = comps.over_point;
	inters_vecs[LIGHT_V] = ft_normalize(ft_sub_tuples(light.position, point));
	light_dot_normal = ft_dot(inters_vecs[LIGHT_V], inters_vecs[NORMAL_V]);
	ft_default_light_values(&(*light_types), material, light);
	if (light_dot_normal >= 0 && !is_shadowed)
	{
		light_types[DIFFUSE] = light_types[EFECTIVE_COLOR];
		ft_scalar_mult(&(light_types[DIFFUSE]), \
			material.diffuse * light_dot_normal, COLOR);
		inters_vecs[REFLECTION_V] = ft_reflection_vector(\
			ft_negate_tuple(inters_vecs[LIGHT_V]), inters_vecs[NORMAL_V]);
		reflect_dot_eye = ft_dot(inters_vecs[REFLECTION_V], \
			inters_vecs[EYE_V]);
		ft_specular_reflection(light, &(light_types[SPECULAR]), \
			reflect_dot_eye, material);
	}
	return (ft_final_color(light_types[AMBIENT], light_types[DIFFUSE], \
		light_types[SPECULAR], material.color));
}

/**
 * Calcular el valor del reflejo especular en caso de que exista.
 */
static void	ft_specular_reflection(t_point_light light, \
	t_tuple *specular_light, double reflect_dot_eye, t_material material)
{
	if (reflect_dot_eye > 0)
	{
		light.brightness = light.brightness * material.specular \
			* pow(reflect_dot_eye, material.shininess);
		*specular_light = ft_build_tuple(light.brightness, \
			light.brightness, light.brightness, COLOR);
	}
}

/**
 * Retorna el color final de un pixel tras aplicarle los ratios de luminosidad.
 * Limitamos los valores de light_ratio a 1, que representa el 100% de 
 * luminosidad de un color, ya que mlx si pasas un numero por encima de 255 
 * comienza la diferencia desde cero. Por ejemplo 256 sería 0 257 1...
 * @param ambt Ratios de luz ambiente a aplicar a cada color.
 * @param diff Ratios de luz difusa a aplicar a cada color.
 * @param spec Ratios de luz especular a aplicar a cada color.
 * @param color Color original del pixel.
 * @return `int` con el código de color final.
 */
static int	ft_final_color(t_tuple ambt, t_tuple diff, t_tuple spec, \
	double color)
{
	t_tuple	light_ratio;

	light_ratio = ft_add_tuples(ambt, diff);
	light_ratio.w = COLOR;
	light_ratio = ft_add_tuples(light_ratio, spec);
	light_ratio.w = COLOR;
	if (light_ratio.x > 1)
		light_ratio.x = 1;
	if (light_ratio.y > 1)
		light_ratio.y = 1;
	if (light_ratio.z > 1)
		light_ratio.z = 1;
	return (ft_create_trgb(0, ft_get_r(color) * light_ratio.x, \
		ft_get_g(color) * light_ratio.y, ft_get_b(color) * light_ratio.z));
}

/**
 * Normaliza los valores del color del objeto, para poder aplicar la 
 * influencia de la luz en el color y define los valores por 
 * defecto de las distintasluces (ambiente, difusa y especular).
 */
static void	ft_default_light_values(t_tuple *light_types, \
	t_material material, t_point_light light)
{
	light_types[EFECTIVE_COLOR] = ft_normalize_color(material.color);
	ft_scalar_mult(&(light_types[EFECTIVE_COLOR]), light.brightness, COLOR);
	light_types[AMBIENT] = ft_mult_tuples(\
		ft_normalize_color(material.color), \
		ft_normalize_color(material.ambient));
	light_types[AMBIENT].w = COLOR;
	light_types[DIFFUSE] = ft_normalize_color(ft_create_trgb(0, 0, 0, 0));
	light_types[SPECULAR] = ft_normalize_color(ft_create_trgb(0, 0, 0, 0));
}
