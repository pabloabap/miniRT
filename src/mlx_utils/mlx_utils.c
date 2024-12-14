/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:19:51 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:19:55 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/**
 * Take a pointer struct with canvas details, pixel (x,y) coordinates, 
 * the color to draw the pixel and fill it in the image.
 * 
 * @param canvas	t_canvas struct with canvas details.
 * @param x			X coordinate of the pixel to draw.
 * @param x			Y coordinate of the pixel to draw.
 * @param color		color to apply to the pixel.
 * 
 * @return Nothing, data is changed directily on image via pointers.
 */
void	ft_mlx_pixel_put(t_canvas *img, int x, int y, int color)
{
	char	*dst;

	dst = img->img_addr + (y * img->line_bytes + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

/**
 * Funcion para hacer zoom en la escena, aumentando el fov de la camara.
 * No confundir zoom con desplazamiento en el espacio.
 * @param scene Estructura con los atributos de la escena.
 * @param fov Nuevo fov de la camara.
 */
void	ft_zoom_camera(t_scene *scene, double fov)
{
	t_camera	cam;
	t_tuple		to_p;

	to_p = ft_sub_tuples(scene->camera->position_p, \
		ft_negate_tuple(scene->camera->orientation_v));
	cam = ft_build_camera(HEIGHT, WIDTH, fov);
	cam.position_p = scene->camera->position_p;
	cam.orientation_v = scene->camera->orientation_v;
	cam.transformations_matrix = ft_matrix_view_transform(\
		cam.position_p, to_p, ft_build_tuple(0, \
			(cam.orientation_v.x != 0 || cam.orientation_v.z != 0), \
			(cam.orientation_v.y < 0) - (cam.orientation_v.y > 0), VECTOR));
	cam.inv_transform = ft_inverse_matrix(&cam.transformations_matrix);
	*(scene->camera) = cam;
}
