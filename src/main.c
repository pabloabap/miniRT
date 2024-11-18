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
	return (s);
}

void	free_obj_lst(t_oitem *o_lst)
{
	t_oitem	*tmp;

	tmp = o_lst;
	if (!o_lst)
		return ;
	while (tmp)
	{
		o_lst = o_lst->next;
		free(tmp->obj_struct);
		free(tmp);
		tmp = o_lst;
	}
	return ;
}

void	free_scene(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->ambient_light)
		free(scene->ambient_light);
	if (scene->light)
		free(scene->light);
	if (scene->camera)
		free(scene->camera);
	if (scene->objs_list)
		free_obj_lst(scene->objs_list);
	free(scene);
}

int	main(void)
{
	t_scene	*scene;
	char	*path = "./scenes/sphere.rt";

	scene = scene_init();
	if (!scene)
		return (perror("Scene initialization: "), EXIT_FAILURE);
	if (read_scene(path, scene))
	{
		free_scene(scene);
		return (EXIT_FAILURE);
	}
	return (0);
}


int	main2(void)
{
	t_scene	*scene;
	char	*path = "./scenes/sphere.rt";

	scene = scene_init();
	if (!scene)
		return (perror("Scene initialization: "), EXIT_FAILURE);
	if (read_scene(path, scene))
	{
		free_scene(scene);
		return (EXIT_FAILURE);
	}
	ft_prepare_canvas(&scene->canvas);
 	// floor
	((t_sphere *)((*scene).objs_list->obj_struct))->transformations_matrix = \
		ft_matrix_scalation(ft_identity_matrix(4, 4), 10, 0.01, 10);
	scene->objs_list->material.specular = 0;
	// left_wall
	((t_sphere *)((*scene).objs_list->next->obj_struct))->transformations_matrix = \
			ft_matrix_translation(\
				ft_matrix_rotation(\
					ft_matrix_rotation(\
						ft_matrix_scalation(ft_identity_matrix(4, 4), 10, 0.01, 10)\
						, X, 90)\
					, Y, -45), \
				0, 0, 5);
	scene->objs_list->next->material.specular = 0;
	// right_wall
	((t_sphere *)((*scene).objs_list->next->next->obj_struct))->transformations_matrix = \
					ft_matrix_translation(\
				ft_matrix_rotation(\
					ft_matrix_rotation(\
						ft_matrix_scalation(ft_identity_matrix(4, 4), 10, 0.01, 10)\
						, X, 90)\
					, Y, 45), \
				0, 0, 5);
	scene->objs_list->next->next->material.specular = 0;
	// Camera
	*(scene->camera) = ft_build_camera(HEIGHT, WIDTH, 60);
	scene->camera->transformations_matrix = ft_matrix_view_transform(\
		ft_build_tuple(0, 1.5, -5, POINT), ft_build_tuple(0, 1, 0, POINT), ft_build_tuple(0, 1, 0, VECTOR));
	ft_render_scene(scene);
	mlx_put_image_to_window(scene->canvas->mlx_init, \
		scene->canvas->mlx_win, scene->canvas->img, 0, 0);
	sleep(10000000);
	return (0);
}
