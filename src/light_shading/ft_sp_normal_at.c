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

#include "../../include/mini_rt.h"

/** Haya la normal sobre un punto especifico en la superficie de una esfera.
 * @param obj Estructura objeto de la esfera a la que pertenece el punto para 
 * 	obtener la matriz con las transformaciones aplicadas.
 * @param surface_point `t_tuple`con las coordenadas del punto de la superfice en
 * 	en el espacio global.
 * @return Vector normal del punto en el espacio global.
 */
t_tuple	ft_sp_normal_at(t_oitem obj, t_tuple surface_point)
{
	t_tuple	obj_point;
	t_tuple	obj_normal;
	t_tuple	world_normal;

	if (obj.obj_type == SPHERE)
	{
		ft_sp_normal_at_check(surface_point.w);
		obj_point = ft_matrix_to_tuple(ft_matrix_mult(\
			obj.inv_transform, \
			ft_tuple_to_matrix(surface_point)));
		obj_normal = ft_build_tuple(obj_point.x, obj_point.y, obj_point.z, VECTOR);
		world_normal = ft_matrix_to_tuple(ft_matrix_mult(\
			ft_matrix_transpos(obj.inv_transform), \
			ft_tuple_to_matrix(obj_normal)));
	}
	if (obj.obj_type == PLANE)
		world_normal = ((t_plane *)(obj.obj_struct))->nrm_vector;
	if (obj.obj_type == CYLINDER)
	{
		t_cylinder cy = *(t_cylinder *)obj.obj_struct;
		float cap = cy.height / 2.0;
		//check
		obj_point = ft_matrix_to_tuple(ft_matrix_mult(\
			obj.inv_transform, \
			ft_tuple_to_matrix(surface_point)));
		if (fabs(obj_point.y - cap) < CY_EPSILON)
     	  	obj_normal = ft_build_tuple(0, 1, 0, VECTOR);
		else if (fabs(obj_point.y + cap) < CY_EPSILON)
     	  	obj_normal = ft_build_tuple(0, -1, 0, VECTOR);
    	else
        	obj_normal = ft_build_tuple(obj_point.x, 0, obj_point.z, VECTOR);
		world_normal = ft_matrix_to_tuple(ft_matrix_mult(\
			ft_matrix_transpos(obj.inv_transform), \
			ft_tuple_to_matrix(obj_normal)));
	}
	world_normal.w = 0;
	return (ft_normalize(world_normal));
}
