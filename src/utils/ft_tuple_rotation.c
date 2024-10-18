//CABECERA

#include "../../include/mini_rt.h"

static t_matrix ft_build_x_rot_matrix(double rot_deg);
static t_matrix ft_build_y_rot_matrix(double rot_deg);
static t_matrix ft_build_z_rot_matrix(double rot_deg);

/**
 * Rota puntos/vectores en el espacio.
 * @param t Punto/vector a trasladar.
 * @param axis Eje sobre el que rotar (X=0,Y=1,Z=2).
 * @param rot_deg Angulo de rotación.
 * 
 * @return Punto/vector `t` rotado.
 */
t_tuple	ft_tuple_rotation(t_tuple t, int axis, double rot_deg)
{
	t_matrix rotation_matrix;
	
	if (X == axis)
		rotation_matrix = ft_build_x_rot_matrix(rot_deg);
	else if (Y == axis)
		rotation_matrix = ft_build_y_rot_matrix(rot_deg);
	else if (Z == axis)
		rotation_matrix = ft_build_z_rot_matrix(rot_deg);

	rotation_matrix = ft_matrix_mult(rotation_matrix, ft_tuple_to_matrix(t));
	return (ft_matrix_to_tuple(rotation_matrix));
}

/**
 * Rota inversa de puntos/vectores en el espacio.
 * @param t Punto/vector a trasladar.
 * @param axis Eje sobre el que rotar (X=0,Y=1,Z=2).
 * @param rot_deg Angulo de rotación.
 * 
 * @return Punto/vector `t` rotado.
 */
t_tuple	ft_inverse_tuple_rotation(t_tuple t, int axis, double rot_deg)
{
	t_matrix rotation_matrix;
	
	if (X == axis)
		rotation_matrix = ft_build_x_rot_matrix(rot_deg);
	else if (Y == axis)
		rotation_matrix = ft_build_y_rot_matrix(rot_deg);
	else if (Z == axis)
		rotation_matrix = ft_build_z_rot_matrix(rot_deg);

	rotation_matrix = ft_inverse_matrix(&rotation_matrix);
	rotation_matrix = ft_matrix_mult(rotation_matrix, ft_tuple_to_matrix(t));
	return (ft_matrix_to_tuple(rotation_matrix));
}

static t_matrix ft_build_x_rot_matrix(double rot_deg)
{
	double		rot_rad;
	t_matrix	rot_matrix;

	rot_rad = rot_deg / 180 * M_PI;
	rot_matrix = ft_identity_matrix(4,4);
	rot_matrix.val[1][1] = cos(rot_rad);
	rot_matrix.val[1][2] = -sin(rot_rad);
	rot_matrix.val[2][1] = sin(rot_rad);
	rot_matrix.val[2][2] = cos(rot_rad);
	return (rot_matrix);
}

static t_matrix ft_build_y_rot_matrix(double rot_deg)
{
	t_matrix	rot_matrix;
	double		rot_rad;

	rot_rad = rot_deg / 180 * M_PI;
	rot_matrix = ft_identity_matrix(4,4);
	rot_matrix.val[0][0] = cos(rot_rad);
	rot_matrix.val[0][2] = sin(rot_rad);
	rot_matrix.val[2][0] = -sin(rot_rad);
	rot_matrix.val[2][2] = cos(rot_rad);
	return (rot_matrix);
}

static t_matrix ft_build_z_rot_matrix(double rot_deg)
{
	t_matrix	rot_matrix;
	double		rot_rad;

	rot_rad = rot_deg / 180 * M_PI;
	rot_matrix = ft_identity_matrix(4,4);
	rot_matrix.val[0][0] = cos(rot_rad);
	rot_matrix.val[0][1] = -sin(rot_rad);
	rot_matrix.val[1][0] = sin(rot_rad);
	rot_matrix.val[1][1] = cos(rot_rad);
	return (rot_matrix);
}
