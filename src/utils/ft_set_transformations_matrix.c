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


t_matrix ft_matrix_rotation_axis_angle(t_tuple axis, double theta) {
    // Normalización del eje (por si acaso)
    double magnitude = sqrt(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
    double ux = axis.x / magnitude;
    double uy = axis.y / magnitude;
    double uz = axis.z / magnitude;

    double cos_theta = cos(theta);
    double sin_theta = sin(theta);
    double one_minus_cos = 1.0 - cos_theta;

    t_matrix rotation;

    // Inicializa dimensiones
    rotation.rows = 4;
    rotation.cols = 4;
    rotation.det = 1.0;  // La rotación no cambia el determinante de una matriz ortogonal

    // Construir la matriz de rotación
    rotation.val[0][0] = cos_theta + ux * ux * one_minus_cos;
    rotation.val[0][1] = ux * uy * one_minus_cos - uz * sin_theta;
    rotation.val[0][2] = ux * uz * one_minus_cos + uy * sin_theta;
    rotation.val[0][3] = 0.0;

    rotation.val[1][0] = uy * ux * one_minus_cos + uz * sin_theta;
    rotation.val[1][1] = cos_theta + uy * uy * one_minus_cos;
    rotation.val[1][2] = uy * uz * one_minus_cos - ux * sin_theta;
    rotation.val[1][3] = 0.0;

    rotation.val[2][0] = uz * ux * one_minus_cos - uy * sin_theta;
    rotation.val[2][1] = uz * uy * one_minus_cos + ux * sin_theta;
    rotation.val[2][2] = cos_theta + uz * uz * one_minus_cos;
    rotation.val[2][3] = 0.0;

    // Última fila para matriz 4x4 (transformaciones homogéneas)
    rotation.val[3][0] = 0.0;
    rotation.val[3][1] = 0.0;
    rotation.val[3][2] = 0.0;
    rotation.val[3][3] = 1.0;

    return rotation;
}

void ft_set_cy_transformations_matrix(t_oitem *obj, t_cylinder *cy) {
    t_tuple up = ft_build_tuple(0, 1, 0, VECTOR);
    t_tuple axis = ft_cross(up, cy->nrm_vector);
    double angle = acos(ft_dot(up, cy->nrm_vector));

    if (ft_magnitude(axis) < 1e-6) {
        axis = ft_build_tuple(1, 0, 0, VECTOR);
    }
    obj->transformations_matrix = ft_matrix_translation(
        ft_matrix_rotation_axis_angle(axis, angle),
        cy->origin.x, cy->origin.y, cy->origin.z);
    cy->origin = ft_build_tuple(0, 0, 0, POINT);
}


static void	ft_set_pl_transformations_matrix(t_oitem *obj, t_plane *pl)
{
    t_tuple up = ft_build_tuple(0, 1, 0, VECTOR);
    t_tuple axis = ft_cross(up, pl->nrm_vector);
    double angle = acos(ft_dot(up, pl->nrm_vector));
    if (fabs(angle) < 1e-6 || fabs(angle) == M_PI)
        obj->transformations_matrix = ft_matrix_translation(ft_identity_matrix(4, 4), pl->origin.x, pl->origin.y, pl->origin.z);
	else
	{
        t_matrix rotation = ft_matrix_rotation_axis_angle(axis, angle);
        obj->transformations_matrix = ft_matrix_translation(rotation, pl->origin.x, pl->origin.y, pl->origin.z);
    }
    pl->origin = ft_build_tuple(0, 0, 0, POINT);
}

/*  CODIGO ANTIGUO QUE NO FUNCIONABA POR SI EL ANTERIOR DEJA DE FUNCIONAR COMO
 * SE ESPERA TENER EN CUENTA LA TRANSFORMACION QUE HAGA FALTA EN EL EJE z.
static void	ft_set_pl_transformations_matrix(t_oitem *obj, t_plane *pl)
{
	double	x_deg;
	double	y_deg;
	double	z_deg;

	x_deg = acos(ft_dot(pl->nrm_vector, ft_build_tuple(0, 1, 0, VECTOR))) \
		* (180 / M_PI);
	y_deg = acos(ft_dot(pl->nrm_vector, ft_build_tuple(0, 0, 1, VECTOR))) \
		* (180 / M_PI);
	z_deg = acos(ft_dot(pl->nrm_vector, ft_build_tuple(1, 1, 0, VECTOR))) \
		* (180 / M_PI);
	ft_normalized_vec_check(pl->nrm_vector);
	obj->transformations_matrix = ft_matrix_translation(\
		ft_matrix_rotation(ft_matrix_rotation(ft_matrix_rotation(\
			ft_identity_matrix(4, 4), X, x_deg), Y, y_deg), Z, z_deg), \
		pl->origin.x, pl->origin.y, pl->origin.z);
	pl->origin = ft_build_tuple(0, 0, 0, POINT);
} */
