/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:18:52 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:18:55 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/mini_rt.h"

static t_matrix	ft_build_x_rot_matrix(double rot_deg);
static t_matrix	ft_build_y_rot_matrix(double rot_deg);
static t_matrix	ft_build_z_rot_matrix(double rot_deg);

/**
 * Rota matrices en el espacio.
 * @param m Matriz a rotar.
 * @param axis Eje sobre el que rotar (X=0,Y=1,Z=2).
 * @param rot_deg Angulo de rotación.
 * 
 * @return Matriz `m` rotada.
 */
t_matrix	ft_matrix_rotation(t_matrix m, int axis, double rot_deg)
{
	t_matrix	rotation_matrix;

	if (X == axis)
		rotation_matrix = ft_build_x_rot_matrix(rot_deg);
	else if (Y == axis)
		rotation_matrix = ft_build_y_rot_matrix(rot_deg);
	else if (Z == axis)
		rotation_matrix = ft_build_z_rot_matrix(rot_deg);
	return (ft_matrix_mult(rotation_matrix, m));
}

/**
 * Rotación inversa de una matriz en el espacio.
 * @param m Matriz a rotar.
 * @param axis Eje sobre el que rotar (X=0,Y=1,Z=2).
 * @param rot_deg Angulo de rotación.
 * 
 * @return Matriz `m` rotada.
 */
t_matrix	ft_matrix_inverse_rotation(t_matrix m, int axis, double rot_deg)
{
	t_matrix	rotation_matrix;

	if (X == axis)
		rotation_matrix = ft_build_x_rot_matrix(rot_deg);
	else if (Y == axis)
		rotation_matrix = ft_build_y_rot_matrix(rot_deg);
	else if (Z == axis)
		rotation_matrix = ft_build_z_rot_matrix(rot_deg);
	rotation_matrix = ft_inverse_matrix(&rotation_matrix);
	return (ft_matrix_mult(rotation_matrix, m));
}

/** Constructuor de la matriz de rotación sobre el eje X
 * @param rot_deg Ángulo de rotación en grados.
 * @return Matriz de rotación sobre el eje X.
 */
static t_matrix	ft_build_x_rot_matrix(double rot_deg)
{
	double		rot_rad;
	t_matrix	rot_matrix;

	rot_rad = rot_deg / 180 * M_PI;
	rot_matrix = ft_identity_matrix(4, 4);
	rot_matrix.val[1][1] = cos(rot_rad);
	rot_matrix.val[1][2] = -sin(rot_rad);
	rot_matrix.val[2][1] = sin(rot_rad);
	rot_matrix.val[2][2] = cos(rot_rad);
	return (rot_matrix);
}

/** Constructuor de la matriz de rotación sobre el eje X
 * @param rot_deg Ángulo de rotación en grados.
 * @return Matriz de rotación sobre el eje Y.
 */
static t_matrix	ft_build_y_rot_matrix(double rot_deg)
{
	t_matrix	rot_matrix;
	double		rot_rad;

	rot_rad = rot_deg / 180 * M_PI;
	rot_matrix = ft_identity_matrix(4, 4);
	rot_matrix.val[0][0] = cos(rot_rad);
	rot_matrix.val[0][2] = sin(rot_rad);
	rot_matrix.val[2][0] = -sin(rot_rad);
	rot_matrix.val[2][2] = cos(rot_rad);
	return (rot_matrix);
}

/** Constructuor de la matriz de rotación sobre el eje X
 * @param rot_deg Ángulo de rotación en grados.
 * @return Matriz de rotación sobre el eje Z.
 */
static t_matrix	ft_build_z_rot_matrix(double rot_deg)
{
	t_matrix	rot_matrix;
	double		rot_rad;

	rot_rad = rot_deg / 180 * M_PI;
	rot_matrix = ft_identity_matrix(4, 4);
	rot_matrix.val[0][0] = cos(rot_rad);
	rot_matrix.val[0][1] = -sin(rot_rad);
	rot_matrix.val[1][0] = sin(rot_rad);
	rot_matrix.val[1][1] = cos(rot_rad);
	return (rot_matrix);
}
