/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_transformations_matrix.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:11:26 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/28 11:11:30 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	ft_set_sp_transformations_matrix(t_oitem *obj, t_sphere *sp);
static void	ft_set_pl_transformations_matrix(t_oitem *obj, t_plane *pl);

/**
 * Establece la matriz de transformación inicial del objeto
 * creado, es decir, la traslación de su origen.
 * @param objs_item Puntero al elemento objeto a transformar.
 * @param o_type Tipo de elemento a transformar.
 * @return Nada, actualiza el atributo `transformations_matrix` del
 * 		objeto.
 */
void	ft_set_transformations_matrix(t_oitem *obj_item, int o_type)
{
	if (SPHERE == o_type)
	{
		ft_set_sp_transformations_matrix(obj_item, \
			((t_sphere *)obj_item->obj_struct));
	}
	else if (PLANE == o_type)
		ft_set_pl_transformations_matrix(obj_item, \
			((t_plane *)obj_item->obj_struct));
	else if (CYLINDER == o_type)
	{
		ft_set_cy_transformations_matrix(obj_item, \
			((t_cylinder *)obj_item->obj_struct));
	}
}

/**
 * Construye la matriz de rotación a aplicar a un plano.
 * @param obj Objeto al que aplicar las transformaciones.
 * @param sp `t_sphere` struct que contiene `obj`.
 * @return Nada. Actualiza mediante punteros el atributo 
 * 		`transformations_matrix` del objeto y el origen de la esfera
 * 		a su origen en las coordenadas del objeto.
 */
static void	ft_set_sp_transformations_matrix(t_oitem *obj, t_sphere *sp)
{
	obj->transformations_matrix = ft_matrix_translation(\
		ft_identity_matrix(4, 4), sp->origin.x, sp->origin.y, sp->origin.z);
	sp->origin = ft_build_tuple(0, 0, 0, POINT);
}

t_matrix	ft_matrix_rotation_axis_angle(t_tuple a, double theta)
{
	double		cos_theta;
	double		sin_theta;
	t_matrix	rotation;

	a = ft_normalize(a);
	cos_theta = cos(theta);
	sin_theta = sin(theta);
	rotation = ft_build_matrix(4, 4);
	rotation.det = 1.0;
	rotation.val[0][0] = cos_theta + a.x * a.x * (1.0 - cos_theta);
	rotation.val[0][1] = a.x * a.y * (1.0 - cos_theta) - a.z * sin_theta;
	rotation.val[0][2] = a.x * a.z * (1.0 - cos_theta) + a.y * sin_theta;
	rotation.val[1][0] = a.y * a.x * (1.0 - cos_theta) + a.z * sin_theta;
	rotation.val[1][1] = cos_theta + a.y * a.y * (1.0 - cos_theta);
	rotation.val[1][2] = a.y * a.z * (1.0 - cos_theta) - a.x * sin_theta;
	rotation.val[2][0] = a.z * a.x * (1.0 - cos_theta) - a.y * sin_theta;
	rotation.val[2][1] = a.z * a.y * (1.0 - cos_theta) + a.x * sin_theta;
	rotation.val[2][2] = cos_theta + a.z * a.z * (1.0 - cos_theta);
	rotation.val[3][3] = 1.0;
	return (rotation);
}

void	ft_set_cy_transformations_matrix(t_oitem *obj, t_cylinder *cy)
{
	t_tuple	up;
	t_tuple	axis;
	double	angle;

	up = ft_build_tuple(0, 1, 0, VECTOR);
	axis = ft_cross(up, cy->nrm_vector);
	angle = acos(ft_dot(up, cy->nrm_vector));
	if (ft_magnitude(axis) < 1e-6)
		axis = ft_build_tuple(1, 0, 0, VECTOR);
	obj->transformations_matrix = ft_matrix_translation(
			ft_matrix_rotation_axis_angle(axis, angle),
			cy->origin.x, cy->origin.y, cy->origin.z);
	cy->origin = ft_build_tuple(0, 0, 0, POINT);
}

static void	ft_set_pl_transformations_matrix(t_oitem *obj, t_plane *pl)
{
	t_tuple		up;
	t_tuple		axis;
	double		angle;
	t_matrix	rotation;

	up = ft_build_tuple(0, 1, 0, VECTOR);
	axis = ft_cross(up, pl->nrm_vector);
	angle = acos(ft_dot(up, pl->nrm_vector));
	if (fabs(angle) < 1e-6 || fabs(angle) == M_PI)
		obj->transformations_matrix = ft_matrix_translation(
				ft_identity_matrix(4, 4),
				pl->origin.x, pl->origin.y, pl->origin.z);
	else
	{
		rotation = ft_matrix_rotation_axis_angle(axis, angle);
		obj->transformations_matrix = ft_matrix_translation(
				rotation, pl->origin.x, pl->origin.y, pl->origin.z);
	}
	pl->origin = ft_build_tuple(0, 0, 0, POINT);
}
