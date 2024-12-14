/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:15:44 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/12 23:16:16 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/**
 * Configura ajuste de la camara.
 * @param hsize Numero de pixeles de alto del lienzo.
 * @param vsize Numero de pizxeles de ancho del lienzo.
 * @param fov_deg Campo de vision en grados (rango 0-180)
 * 
 * @return Estructura `t_camera` configurada.
 */
t_camera	ft_build_camera(int hsize, int vsize, int fov_deg)
{
	t_camera	camera;
	double		half_view;
	double		aspect;

	if (fov_deg < 0 || fov_deg > 180)
		exit(printf("Error\nFOV out of range\n"));
	camera.hsize = hsize;
	camera.vsize = vsize;
	camera.fov = M_PI * fov_deg / 180;
	camera.transformations_matrix = ft_identity_matrix(4, 4);
	half_view = tan(camera.fov / 2);
	aspect = camera.hsize / camera.vsize;
	if (aspect >= 1)
	{
		camera.half_width = half_view;
		camera.half_height = half_view / aspect;
	}
	else
	{
		camera.half_width = half_view * aspect;
		camera.half_height = half_view;
	}
	camera.pixel_size = (camera.half_width * 2) / camera.hsize;
	return (camera);
}
