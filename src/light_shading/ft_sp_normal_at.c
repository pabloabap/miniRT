/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_normal_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:16:48 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:16:50 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_tuple	sp_normal(t_oitem obj, t_tuple s_point)
{
	t_tuple	obj_point;
	t_tuple	obj_normal;
	t_tuple	world_normal;

	ft_sp_normal_at_check(s_point.w);
	obj_point = ft_matrix_to_tuple(ft_matrix_mult(\
		obj.inv_transform, \
		ft_tuple_to_matrix(s_point)));
	obj_normal = ft_build_tuple(obj_point.x, obj_point.y, obj_point.z, VECTOR);
	world_normal = ft_matrix_to_tuple(ft_matrix_mult(\
		ft_matrix_transpos(obj.inv_transform), \
		ft_tuple_to_matrix(obj_normal)));
	return (world_normal);
}

t_tuple	cy_normal(t_oitem obj, t_tuple s_point)
{
	t_cylinder	cy;
	t_tuple		obj_point;
	t_tuple		obj_normal;
	t_tuple		world_normal;

	cy = *(t_cylinder *)obj.obj_struct;
	obj_point = ft_matrix_to_tuple(ft_matrix_mult(\
		obj.inv_transform, \
		ft_tuple_to_matrix(s_point)));
	if (fabs(obj_point.y - cy.height / 2.0) < CY_EPSILON)
		obj_normal = ft_build_tuple(0, 1, 0, VECTOR);
	else if (fabs(obj_point.y + cy.height / 2.0) < CY_EPSILON)
		obj_normal = ft_build_tuple(0, -1, 0, VECTOR);
	else
		obj_normal = ft_build_tuple(obj_point.x, 0, obj_point.z, VECTOR);
	world_normal = ft_matrix_to_tuple(ft_matrix_mult(\
		ft_matrix_transpos(obj.inv_transform), \
		ft_tuple_to_matrix(obj_normal)));
	return (world_normal);
}

/** Haya la normal sobre un punto especifico en la superficie de una esfera.
 * @param obj Estructura objeto de la esfera a la que pertenece el punto para 
 * 	obtener la matriz con las transformaciones aplicadas.
 * @param surface_point `t_tuple`con las coordenadas del punto de la superfice en
 * 	en el espacio global.
 * @return Vector normal del punto en el espacio global.
 */
t_tuple	ft_sp_normal_at(t_oitem obj, t_tuple surface_point)
{
	t_tuple	world_normal;

	if (obj.obj_type == SPHERE)
		world_normal = sp_normal(obj, surface_point);
	if (obj.obj_type == PLANE)
		world_normal = ((t_plane *)(obj.obj_struct))->nrm_vector;
	if (obj.obj_type == CYLINDER)
		world_normal = cy_normal(obj, surface_point);
	world_normal.w = 0;
	return (ft_normalize(world_normal));
}
