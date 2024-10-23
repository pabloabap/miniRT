//CABECERA

#include "../../../include/mini_rt.h"

static t_matrix ft_build_scal_matrix(double x, double y, double z);

/**
 * Escala puntos/vectores en el espacio.
 * Escalar un vector, lo hace más largo.
 * @param p Punto a escalar.
 * @param x Unidades de escalado en la coordenada X.
 * @param y Unidades de escalado en la coordenada Y.
 * @param z Unidades de escalado en la coordenada Z.
 * 
 * @return Punto nuevo con las coordenadas de `p`
 * tras aplicar el escalado.
 */
t_tuple	ft_tuple_scalation(t_tuple p, double x, double y, double z)
{
	t_matrix	tmp;
	t_matrix	scal_matrix;

	scal_matrix = ft_build_scal_matrix(x, y, z);
	tmp = ft_matrix_mult(scal_matrix, ft_tuple_to_matrix(p));
	return (ft_matrix_to_tuple(tmp));
}

/**
 * Escalación inversa. Sirve para escalar puntos/vectores en el espacio
 * en la dirección opesta a las coordenadas indicadas.
 * @param p Punto a escalar.
 * @param x Unidades de escalado en la coordenada X.
 * @param y Unidades de escalado en la coordenada Y.
 * @param z Unidades de escalado en la coordenada Z.
 * 
 * @return Punto nuevo con las coordenadas de `p`
 * tras aplicar el escalado inverso.
 */
t_tuple	ft_tuple_inverse_scalation(t_tuple p, double x, double y, double z)
{
	t_matrix	tmp;
	t_matrix	scal_matrix;

	scal_matrix = ft_build_scal_matrix(x, y, z);
	scal_matrix = ft_inverse_matrix(&scal_matrix);
	tmp = ft_matrix_mult(scal_matrix, ft_tuple_to_matrix(p));
	return (ft_matrix_to_tuple(tmp));
}

/**
 * Construcción de la matriz para realizar la operación de escalado.
 * Se obtiene cambiando los tres primeros elementos de la diagonal de la 
 * matriz identidad por  las unidades `x`, `y` y `z` que queramos escalar.
 */
static t_matrix ft_build_scal_matrix(double x, double y, double z)
{
	t_matrix	trans_matrix;

	trans_matrix = ft_identity_matrix(4,4);
	trans_matrix.val[0][0] = x;
	trans_matrix.val[1][1] = y;
	trans_matrix.val[2][2] = z;
	trans_matrix.val[3][3] = 1;
	return (trans_matrix);
}