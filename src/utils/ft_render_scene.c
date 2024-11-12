/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:16:38 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/07 19:07:16 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static int			ft_process_pixel(int	*canvas_axis, int *world_axis, \
	t_scene *scene, t_ray ray);
static int			ft_detect_ray_inters(t_oitem *o_list, \
	t_ray_inters **i_list, t_ray ray);
static int			ft_scene_lighting(t_ray ray, t_ray_inters *ray_inters, \
	t_scene *scene, int *canvas_axis);
static t_pre_comp	ft_prepare_computation(t_ray ray, t_ray_inters *inters);

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
			ft_process_pixel(&(*canvas_axis), &(*world_axis), scene, ray);
			canvas_axis[X]++;
		}
		canvas_axis[X] = 0;
		canvas_axis[Y]++;
	}
	return (EXIT_SUCCESS);
}

/**
 * Realiza las operaciones de renderizado de un pixel.
 * @param canvas_axis Array de dos enteros (posicion X e Y de un pixel)
 * 		en la ventana. Siendo el punto (0, 0) la esquina superior izquierda.
 * @param world_axis Array de dos enteros (posicion X e Y de un pixel)
 * 		en el mundo real. Siendo el punto (0, 0) el centro de la imagen.
 * @param	scene Estructua con todos los atributos de la escena.
 * @param	ray Estructura t_ray con informacion del origen y la direccion
 * 		del rayo que parte de la camara hasta un punto de la imagen.
 * @return Resultado de la ejecucion.
 */
static int	ft_process_pixel(int *canvas_axis, int *world_axis, \
	t_scene *scene, t_ray ray)
{
	t_tuple			wall_point;
	t_ray_inters	*ray_inters;

	world_axis[X] = -WIDTH / 2 + canvas_axis[X];
	wall_point = ft_build_tuple(world_axis[X], world_axis[Y], scene->z_wall, \
		POINT);
	ray_inters = NULL;
	ray.direction = ft_normalize(ft_sub_tuples(wall_point, ray.origin));
	ft_detect_ray_inters(scene->objs_list, \
		&(ray_inters), ray);
	ft_scene_lighting(ray, ray_inters, scene, &(*canvas_axis));
	ft_free_ray_inters_list(ray_inters);
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
	int		status;
	t_ray	tmp;

	status = EXIT_SUCCESS;
	while (EXIT_SUCCESS == status && o_list)
	{
		tmp = ray;
		tmp.origin = ft_matrix_to_tuple(ft_matrix_mult(\
				ft_inverse_matrix(\
				&((t_sphere *)(o_list->obj_struct))->transformations_matrix), \
				ft_tuple_to_matrix(ray.origin)));
		tmp.direction = ft_matrix_to_tuple(ft_matrix_mult(\
				ft_inverse_matrix(\
				&((t_sphere *)(o_list->obj_struct))->transformations_matrix), \
				ft_tuple_to_matrix(ray.direction)));
		ft_sphere_inters(tmp, o_list, i_list);
		o_list = o_list->next;
	}
	return (status);
}

/**
 * Aplica los porcentajes de luminosidad al color de un pixel de la escena.
 * @param ray Rayo con origen en la posicion de la camara y direccion hacia un
 * 		punto de la escena.
 * @param inters Puntero a la lista de intersecciones de un rayo.
 * @param	scene Estructua con todos los atributos de la escena.
 * @param canvas_axis Array de dos enteros (posicion X e Y de un pixel)
 * 		en la ventana. Siendo el punto (0, 0) la esquina superior izquierda.
 * @return Resultado de la ejecucion.
 */
static int	ft_scene_lighting(t_ray ray, t_ray_inters *inters, \
	t_scene *scene, int *canvas_axis)
{
	t_pre_comp		comps;

	if (ft_identify_hit(inters))
	{
		comps = ft_prepare_computation(ray, inters);
		ft_mlx_pixel_put(scene->canvas, canvas_axis[X], canvas_axis[Y], \
			ft_lighting(comps.obj->material, *scene->light, comps.hit_point, \
			&(*(comps.inters_vecs))));
	}
	return (EXIT_SUCCESS);
}

/**
 * Rellena los datos de la estructura `t_pre_comp` para optimizar los tiempos
 * de renderizado.
 * @param ray Estructura con origen de la camara y dirección del rayo a 
 * 	computar.
 * @param inters Lista de intersecciones del rayo.
 * @return Estructura `t_pre_comp`rellena con los datos necesarios para 
 * 	optimizar tiempos de renderizado.
 */
static t_pre_comp	ft_prepare_computation(t_ray ray, t_ray_inters *inters)
{
	t_pre_comp		comps;
	t_ray_inters	*hitted;

	hitted = ft_get_hit(inters);
	comps.inter_point = hitted->inter_point;
	comps.obj = hitted->obj;
	ft_scalar_mult(&(ray.direction), hitted->inter_point, \
			VECTOR);
	comps.hit_point = ft_add_tuples(ray.origin, ray.direction);
	comps.inters_vecs[NORMAL_V] = \
			ft_sp_normal_at(*(t_sphere *)(hitted->obj->obj_struct), \
				comps.hit_point);
	comps.inters_vecs[EYE_V] = ft_negate_tuple(ft_normalize(ray.direction));
	if (0.0 > ft_dot(comps.inters_vecs[NORMAL_V], comps.inters_vecs[EYE_V]))
	{
		comps.inters_vecs[NORMAL_V] = \
			ft_negate_tuple(comps.inters_vecs[NORMAL_V]);
		comps.inside_flag = 1;
	}
	else
		comps.inside_flag = 0;
	return (comps);
}
