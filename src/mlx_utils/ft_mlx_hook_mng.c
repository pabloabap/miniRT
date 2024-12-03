/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook_mng.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:10:56 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/28 11:11:01 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	ft_exit_mlx(t_canvas *canvas);
static int	ft_keyboard_hooks(int keycode, t_scene *scene);

/**
 * Maneja los eventos recibidos por el programa.
 * @param scene Estructura con los atributos de la escena.
 */
void	ft_mlx_hook_mng(t_scene *scene)
{
	mlx_hook(scene->canvas->mlx_win, ON_DESTROY, NO_EVENT, ft_exit_mlx, \
		scene->canvas);
	mlx_hook(scene->canvas->mlx_win, ON_KEYPRESS, KEYPRESS, ft_keyboard_hooks, \
		scene);
}

/**
 * Funcion para salir limpiamete del programa, destruyendo la imagen y ventanan
 * generadas.
 * @param canvas Estructura con atributos de la mlx.
 */
static int	ft_exit_mlx(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx_init, canvas->img);
	mlx_destroy_window(canvas->mlx_init, canvas->mlx_win);
	exit(0);
	return (0);
}

/**
 * Funcion para gestionar los eventos de tecado.
 * @param keycode Codigo identificativo de una tecla.
 * @param scene Estructura con los atributos de la escena.
 */
static int	ft_keyboard_hooks(int keycode, t_scene *scene)
{
	if (keycode == ESC)
		ft_exit_mlx(scene->canvas);
	else if (keycode == PLUS || keycode == MINUS)
	{
		if ((keycode == PLUS && (scene->camera->fov * 180 / M_PI - 10) > 0) \
		|| (keycode == MINUS && (scene->camera->fov * 180 / M_PI + 10) < 180))
		{
			mlx_destroy_image(scene->canvas->mlx_init, scene->canvas->img);
			scene->canvas->img = mlx_new_image(scene->canvas->mlx_init, \
					WIDTH, HEIGHT);
			ft_zoom_camera(scene, scene->camera->fov * 180 / M_PI + 10 \
				* (keycode + 1 - MINUS));
			ft_render_scene(scene);
			mlx_put_image_to_window(scene->canvas->mlx_init, \
				scene->canvas->mlx_win, scene->canvas->img, 0, 0);
		}
		else
			mlx_string_put(scene->canvas->mlx_init, scene->canvas->mlx_win, \
				WIDTH / 2, HEIGHT / 2, set_rgb(255, 255, 255), \
					"Max zoom reached");
	}
	return (0);
}
