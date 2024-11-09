/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:15:35 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:15:43 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

t_scene	*scene_init(void)
{
	t_scene	*s;

	s = malloc(sizeof(t_scene));
	if (!s)
		return (NULL);
	s->camera = NULL;
	s->canvas = NULL;
	s->light = NULL;
	s->objs_list = NULL;
	s->rays_inter_list = NULL;
	s->z_wall = 100;
	return (s);
}

int main(void)
{
	t_scene	*scene;
	char	*path = "./scenes/test.rt";

	scene = scene_init();
	if (!scene)
		return (perror("Scene initialization: "), EXIT_FAILURE);
	if (!read_scene(path, scene))
		return (EXIT_FAILURE);
	
	return (0);
}
/* 
 int	main(void)
{
	t_scene		*scene;
	t_omodel	model;

	scene = NULL;
	ft_prepare_scence(&scene);
	model.sp = ft_build_sphere(ft_build_tuple(0, 0, 50, POINT), 40);
	model.sp.transformations_matrix = \
		ft_matrix_translation(model.sp.transformations_matrix, 0, 0, 20);
	ft_add_obj(&(scene->objs_list), model, SPHERE, \
		ft_create_trgb(0, 255, 255 * 0.2, 255));
	scene->objs_list->material.ambient = 0.5;
	scene->objs_list->material.diffuse = 0.5;
	scene->objs_list->material.specular = 0.5;
	scene->objs_list->material.shininess -= 1;
	ft_render_scene(scene);
	mlx_put_image_to_window(scene->canvas->mlx_init, \
		scene->canvas->mlx_win, scene->canvas->img, 0, 0);
	sleep(10);
	return (0);
}  */
