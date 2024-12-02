/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_ray_inters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:14:42 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/15 15:14:45 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	ft_plane_inters(t_ray ray, t_oitem *plane, t_ray_inters **i_list);

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
int	ft_detect_ray_inters(t_oitem *o_list, t_ray_inters **i_list, t_ray ray)
{
	int		status;
	t_ray	tmp;

	status = EXIT_SUCCESS;
	while (EXIT_SUCCESS == status && o_list)
	{
		tmp = ray;
		tmp.origin = ft_matrix_to_tuple(ft_matrix_mult(\
				o_list->inv_transform, \
				ft_tuple_to_matrix(ray.origin)));
		tmp.direction = ft_matrix_to_tuple(ft_matrix_mult(\
				o_list->inv_transform, \
				ft_tuple_to_matrix(ray.direction)));
		if (SPHERE == o_list->obj_type)
			ft_sphere_inters(tmp, o_list, i_list);
		else if (PLANE == o_list->obj_type)
			ft_plane_inters(tmp, o_list, i_list);
		else if (CYLINDER == o_list->obj_type)
			ft_cylinder_inters(tmp, o_list, i_list);
		o_list = o_list->next;
	}
	return (status);
}

/**
 * Añade datos de intersección de un rayo con un objeto de tipo plano a la
 * lista de intersecciones del rayo.
 * @param ray Rayo que intersecta.
 * @param plane Puntero a un objeto de tipo plano.
 * @param i_list Lista de intersecciones del rayo.
 * @return Nada. Añade la intersección del rayo con el plano, si la hay,
 * 		a la lista de intersecciones del rayo.
 */
static void	ft_plane_inters(t_ray ray, t_oitem *plane, t_ray_inters **i_list)
{
	double	tan;

	if (fabs(ray.direction.y) > __FLT_EPSILON__)
	{
		tan = -ray.origin.y / ray.direction.y;
		if (!isnan(tan))
			ft_add_inters_sorted(i_list, tan, plane);
	}
}
