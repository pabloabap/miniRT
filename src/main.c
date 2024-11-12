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

int	main(void)
{
	t_scene		*scene;
	t_omodel	model;

	scene = NULL;
	ft_prepare_scence(&scene);
	// floor
	model.sp = ft_build_sphere(ft_build_tuple(0, 0, 0, POINT), 1);
	model.sp.transformations_matrix = \
		ft_matrix_scalation(model.sp.transformations_matrix, 10, 0.01, 10);
	ft_add_obj(&(scene->objs_list), model, SPHERE, \
		ft_create_trgb(0, 255, 255 * 0.9, 255 * 0.9));
	ft_modify_material_property(scene->objs_list, 0, SPECULAR, 0);
	// left_wall
	model.sp = ft_build_sphere(ft_build_tuple(0, 0, 0, POINT), 1);
	model.sp.transformations_matrix = \
			ft_matrix_translation(\
				ft_matrix_rotation(\
					ft_matrix_rotation(\
						ft_matrix_scalation(model.sp.transformations_matrix, 10, 0.01, 10)\
						, X, 90)\
					, Y, -45), \
				0, 0, 5);
		ft_add_obj(&(scene->objs_list), model, SPHERE, \
		ft_create_trgb(0, 255, 255 * 0.9, 255 * 0.9));
	ft_modify_material_property(scene->objs_list, 1, SPECULAR, 0);
	// right_wall
	model.sp = ft_build_sphere(ft_build_tuple(0, 0, 0, POINT), 1);
	model.sp.transformations_matrix = \
					ft_matrix_translation(\
				ft_matrix_rotation(\
					ft_matrix_rotation(\
						ft_matrix_scalation(model.sp.transformations_matrix, 10, 0.01, 10)\
						, X, 90)\
					, Y, 45), \
				0, 0, 5);
	ft_add_obj(&(scene->objs_list), model, SPHERE, \
		ft_create_trgb(0, 255, 255 * 0.9, 255 * 0.9));
	ft_modify_material_property(scene->objs_list, 2, SPECULAR, 0);
	// Sphere 1
	model.sp = ft_build_sphere(ft_build_tuple(0, 0, 0, POINT), 1);
	model.sp.transformations_matrix = \
		ft_matrix_translation(model.sp.transformations_matrix, 0.1, 1, 0.5);
	ft_add_obj(&(scene->objs_list), model, SPHERE, \
		ft_create_trgb(0, 255 * 0.1, 255 * 1, 255 * 0.5));
	ft_modify_material_property(scene->objs_list, 3, SPECULAR, 0.3);
	ft_modify_material_property(scene->objs_list, 3, DIFFUSE, 0.7);
	// Sphere 2
	model.sp = ft_build_sphere(ft_build_tuple(0, 0, 0, POINT), 1);
	model.sp.transformations_matrix = \
		ft_matrix_translation(\
			ft_matrix_scalation(model.sp.transformations_matrix, 0.5, 0.5, 0.5), 1.5, 0.5, -0.5);
	ft_add_obj(&(scene->objs_list), model, SPHERE, \
		ft_create_trgb(0, 255 * 0.5, 255 * 1, 255 * 0.1));
	ft_modify_material_property(scene->objs_list, 4, SPECULAR, 0.3);
	ft_modify_material_property(scene->objs_list, 4, DIFFUSE, 0.7);
	// Sphere 3
	model.sp = ft_build_sphere(ft_build_tuple(0, 0, 0, POINT), 1);
	model.sp.transformations_matrix = \
		ft_matrix_translation(\
			ft_matrix_scalation(model.sp.transformations_matrix, 0.33, 0.33, 0.33), -1.5, 0.33, -0.75);
	ft_add_obj(&(scene->objs_list), model, SPHERE, \
		ft_create_trgb(0, 255 * 1, 255 * 0.8, 255 * 0.1));
	ft_modify_material_property(scene->objs_list, 5, SPECULAR, 0.3);
	ft_modify_material_property(scene->objs_list, 5, DIFFUSE, 0.7);
	// Light
	scene->light = ft_build_light(ft_build_tuple(-10, 10, -10, POINT), 1);
	// Camera
	scene->camera = ft_build_camera(HEIGHT, WIDTH, 60);
	scene->camera.transformations_matrix = ft_matrix_view_transform(\
		ft_build_tuple(0, 1.5, -5, POINT), ft_build_tuple(0, 1, 0, POINT), ft_build_tuple(0, 1, 0, VECTOR));
	//Render
	ft_render_scene(scene);
	mlx_put_image_to_window(scene->canvas->mlx_init, \
		scene->canvas->mlx_win, scene->canvas->img, 0, 0);
	sleep(10);
	return (0);
}
