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
int	ft_detect_ray_inters2(t_oitem *o_list, t_ray_inters **i_list, t_ray ray)
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

int	ft_detect_ray_inters(t_oitem *o_list, t_ray_inters **i_list, t_ray ray)
{
	int		status;
	t_ray	tmp;
	t_matrix	inv;

	status = EXIT_SUCCESS;
	while (EXIT_SUCCESS == status && o_list)
	{
		//inv = ft_inverse_matrix(&((t_sphere *)(o_list->obj_struct))->transformations_matrix);
		tmp = ray;
		tmp.origin = ft_matrix_to_tuple(ft_matrix_mult(\
				((t_sphere *)(o_list->obj_struct))->inv_transform, \
				ft_tuple_to_matrix(ray.origin)));
		tmp.direction = ft_matrix_to_tuple(ft_matrix_mult(\
				((t_sphere *)(o_list->obj_struct))->inv_transform, \
				ft_tuple_to_matrix(ray.direction)));
		ft_sphere_inters(tmp, o_list, i_list);
		o_list = o_list->next;
	}
	return (status);
}
