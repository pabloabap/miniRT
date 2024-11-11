/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:19:05 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/07 15:20:44 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static void	ft_prepare_canvas(t_canvas **canvas);

/**
 * Funcion para preparar los valores iniciales de la escena.
 */
int	ft_prepare_scence(t_scene **scene)
{
	t_scene	*initialized_scene;

	initialized_scene = (t_scene *)malloc(sizeof(t_scene));
	if (NULL == initialized_scene)
		return (EXIT_FAILURE);
	*scene = initialized_scene;
	(*scene)->light = \
		ft_build_light(ft_build_tuple(-60, -60, 0, POINT), 0.6);
	(*scene)->objs_list = NULL;
	(*scene)->canvas = NULL;
	ft_prepare_canvas(&((*scene)->canvas));
	(*scene)->z_wall = 100;
	(*scene)->camera.position_p = ft_build_tuple(0, 0, 0, POINT);
	return (EXIT_SUCCESS);
}

/**
 * Inicializa ventana, imagenes y atributos de las mismas.
 */
static void	ft_prepare_canvas(t_canvas **canvas)
{
	t_canvas	*initialized_canvas;

	initialized_canvas = (t_canvas *)malloc(sizeof(t_canvas));
	(*canvas) = initialized_canvas;
	(*canvas)->mlx_init = mlx_init();
	ft_mlx_failure_check((*canvas)->mlx_init);
	(*canvas)->mlx_win = mlx_new_window((*canvas)->mlx_init, WIDTH, HEIGHT, \
		"miniRT");
	ft_mlx_failure_check((*canvas)->mlx_win);
	(*canvas)->img = mlx_new_image((*canvas)->mlx_init, WIDTH, HEIGHT);
	ft_mlx_failure_check((*canvas)->img);
	(*canvas)->img_addr = mlx_get_data_addr((*canvas)->img, &((*canvas)->bpp), \
		&((*canvas)->line_bytes), &((*canvas)->endian));
}
