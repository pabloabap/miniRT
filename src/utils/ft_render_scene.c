/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:16:38 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/07 15:18:34 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static int	ft_process_line(int	*canvas_axis, int *world_axis, \
	t_scene *scene, t_ray ray);
static int	ft_detect_ray_inters(t_oitem *o_list, t_ray_inters **i_list, \
	t_ray ray);
static int	ft_scene_lighting(t_ray ray, t_scene *scene, int *canvas_axis);

/**
 * Procesa los datos de los objetos para dibujar la imagen.
 * @param	scene Estructua con todos los atributos de la escena.
 * @return	Entero con el resultado de la ejecucion.
 */
int	ft_render_scene(t_scene *scene)
{
	int		canvas_axis[2];
	int		world_axis[2];
	t_ray	ray;

	ray.origin = scene->camera->position_p;
	canvas_axis[X] = 0;
	canvas_axis[Y] = 0;
	while (canvas_axis[Y] < HEIGHT)
	{
		world_axis[Y] = HEIGHT / 2 - canvas_axis[Y];
		while (canvas_axis[X] < WIDTH)
		{
			ft_process_line(&(*canvas_axis), &(*world_axis), scene, ray);
			canvas_axis[X]++;
		}
		canvas_axis[X] = 0;
		canvas_axis[Y]++;
	}
	return (EXIT_SUCCESS);
}

/**
 * Realiza las operaciones de renderizado de una linea de pixeles.
 * @param canvas_axis Array de dos enteros (posicion X e Y de un pixel)
 * 		en la ventana. Siendo el punto (0, 0) la esquina superior izquierda.
 * @param world_axis Array de dos enteros (posicion X e Y de un pixel)
 * 		en el mundo real. Siendo el punto (0, 0) el centro de la imagen.
 * @param	scene Estructua con todos los atributos de la escena.
 * @param	ray Estructura t_ray con informacion del origen y la direccion
 * 		del rayo que parte de la camara hasta un punto de la imagen.
 * @return Resultado de la ejecucion.
 */
static int	ft_process_line(int	*canvas_axis, int *world_axis, \
	t_scene *scene, t_ray ray)
{
	t_tuple	wall_point;

	world_axis[X] = -WIDTH / 2 + canvas_axis[X];
	wall_point = ft_build_tuple(world_axis[X], world_axis[Y], scene->z_wall, \
		POINT);
	ray.direction = ft_normalize(ft_sub_tuples(wall_point, ray.origin));
	ft_add_item_to_inters_list(&(scene->rays_inter_list));
	ft_detect_ray_inters(scene->objs_list, \
		&(ft_lst_inters_item(scene->rays_inter_list)->r_i), ray);
	ft_scene_lighting(ray, scene, &(*canvas_axis));
	return (EXIT_SUCCESS);
}

/**
 * Detecta los puntos de interseccion de los rayos con origen en la camara y 
 * los objetos de la escena.
 * @param o_list Puntero a la primera estructura de la lista de objetos de la
 * 		escena.
 * @param i_list Doble puntero al puntero que debe apuntar al primer elemente
 * 		de la lista de intersecciones, que esta ordenada de menor a mayor.
 * 		Necesario para actualizar los valores a los que apunta.
 * @param ray Rayo con origen en la posicion de la camara y direccion hacia un
 * 		punto de la escena.
 * @return Resultado de la ejecucion.
 */
static int	ft_detect_ray_inters(t_oitem *o_list, t_ray_inters **i_list, \
	t_ray ray)
{
	while (o_list)
	{
		ft_sphere_inters(ray, *(o_list), i_list);
		o_list = o_list->next;
	}
	return (EXIT_SUCCESS);
}

/**
 * Aplica los porcentajes de luminosidad al color de un pixel de la escena.
 * @param ray Rayo con origen en la posicion de la camara y direccion hacia un
 * 		punto de la escena.
 * @param	scene Estructua con todos los atributos de la escena.
 * @param canvas_axis Array de dos enteros (posicion X e Y de un pixel)
 * 		en la ventana. Siendo el punto (0, 0) la esquina superior izquierda.
 * @return Resultado de la ejecucion.
 */
static int	ft_scene_lighting(t_ray ray, t_scene *scene, int *canvas_axis)
{
	t_ray_inters	*ray_inters;
	t_tuple			h_point;
	t_tuple			inters_vecs[4];
	t_oitem			*h_obj;

	ray_inters = ft_lst_inters_item(scene->rays_inter_list)->r_i;
	if (ft_identify_hit(ray_inters))
	{
		h_obj = ft_get_hitted_obj(ray_inters, scene->objs_list);
		ft_scalar_mult(&(ray.direction), ft_get_hit(ray_inters)->inter_point, \
			VECTOR);
		h_point = ft_add_tuples(ray.origin, ray.direction);
		inters_vecs[NORMAL_V] = \
			ft_sp_normal_at(*(t_sphere *)(h_obj->obj_struct), h_point);
		inters_vecs[EYE_V] = ft_negate_tuple(ft_normalize(ray.direction));
		ft_mlx_pixel_put(scene->canvas, canvas_axis[X], canvas_axis[Y], \
			ft_lighting(h_obj->material, *scene->light, h_point, \
			&(*inters_vecs)));
	}
	return (EXIT_SUCCESS);
}
