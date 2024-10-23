//CABECERA

#include "../../../include/mini_rt.h"

/**
 * Permite inclinar puntos/vectores en base a otros ejes.
 * @param t Punto/vector sobre el que aplicar la función.
 * @param axis Eje que va a moverse.
 * @param over_axis Eje base, en proporción al cual se va a moder
 * 		`axis`.
 * @param val Unidades de inclinación a aplicar.
 * 
 * @return El punto/vector inclinado.
 */
t_tuple	ft_tuple_shearing(t_tuple t, int axis, int over_axis, double val)
{
	t_matrix	shearing_matrix;

	shearing_matrix = ft_identity_matrix(4,4);
	shearing_matrix.val[axis][over_axis] = val;
	shearing_matrix = ft_matrix_mult(shearing_matrix, ft_tuple_to_matrix(t));
	return (ft_matrix_to_tuple(shearing_matrix));	
}

/**
 * Permite inclinación inversa de puntos/vectores en base a otros ejes.
 * @param t Punto/vector sobre el que aplicar la función.
 * @param axis Eje que va a moverse.
 * @param over_axis Eje base, en proporción al cual se va a moder
 * 		`axis`.
 * @param val Unidades de inclinación a aplicar.
 * 
 * @return El punto/vector inclinado.
 */
t_tuple	ft_tuple_inverse_shearing(t_tuple t, int axis, int over_axis, double val)
{
	t_matrix	shearing_matrix;

	shearing_matrix = ft_identity_matrix(4,4);
	shearing_matrix.val[axis][over_axis] = val;
	shearing_matrix = ft_inverse_matrix(&shearing_matrix);;
	shearing_matrix = ft_matrix_mult(shearing_matrix, ft_tuple_to_matrix(t));
	return (ft_matrix_to_tuple(shearing_matrix));
}