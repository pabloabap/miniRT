/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_for_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:13:28 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/28 11:09:10 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/**
 * Computa las coordenadas de la escena en el centro del pixel
 * dado y construye el rayo que pasa a traves de ese punto.
 * @param camera Estructura `t_camera` con informacion de la camara.
 * @param px Coordenada `X` del pixel.
 * @param py Coordenada `Y` del pixel.
 * @return Rayo configurado.
 */
t_ray	ft_ray_for_pixel(t_camera camera, double px, double py)
{
	double	offset[2];
	double	world[2];
	t_tuple	pixel_p;
	t_ray	ray;

	offset[X] = (px + 0.5) * camera.pixel_size;
	offset[Y] = (py + 0.5) * camera.pixel_size;
	world[X] = camera.half_width - offset[X];
	world[Y] = camera.half_height - offset[Y];
	pixel_p = ft_matrix_to_tuple(ft_matrix_mult(\
		camera.inv_transform, \
		ft_tuple_to_matrix(ft_build_tuple(world[X], world[Y], -1, POINT))));
	ray.origin = ft_matrix_to_tuple(ft_matrix_mult(camera.inv_transform, \
		ft_tuple_to_matrix(ft_build_tuple(0, 0, 0, POINT))));
	ray.direction = ft_normalize(ft_sub_tuples(pixel_p, ray.origin));
	return (ray);
}
