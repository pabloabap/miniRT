//CABECERA

#include "../../include/mini_rt.h"

static t_matrix ft_build_trans_matrix(double x, double y, double z);

/**
 * Traslada puntos en el espacio.
 * En caso de que `p` sea vector la operación será ignorada.
 * Un vector representa una dirección de desplazamiento, moverlo en el espacio
 * no varía su dirección.
 * @param p Punto a trasladar.
 * @param x Unidades de traslando en la coordenada X.
 * @param y Unidades de traslando en la coordenada Y.
 * @param z Unidades de traslando en la coordenada Z.
 * 
 * @return Punto nuevo con las coordenadas del punto `p`
 * tras aplicar la traslación.
 */
t_tuple	ft_tuple_translation(t_tuple p, double x, double y, double z)
{
	t_matrix	tmp;
	t_matrix	trans_matrix;

	trans_matrix = ft_build_trans_matrix(x, y, z);
	tmp = ft_matrix_mult(trans_matrix, ft_tuple_to_matrix(p));
	return (ft_matrix_to_tuple(tmp));
}

/**
 * Traslación inversa. Sirve para mover puntos en el espacio
 * en la dirección opesta a las coordenadas indicadas.
 * En caso de que `p` sea vector la operación será ignorada.
 * Un vector representa una dirección de desplazamiento, moverlo en el espacio
 * no varía su dirección.
 * @param p Punto a trasladar.
 * @param x Unidades de traslando en la coordenada X.
 * @param y Unidades de traslando en la coordenada Y.
 * @param z Unidades de traslando en la coordenada Z.
 * 
 * @return Punto nuevo con las coordenadas del punto `p`
 * tras aplicar la traslación.
 */
t_tuple	ft_inverse_tuple_translation(t_tuple p, double x, double y, double z)
{
	t_matrix	tmp;
	t_matrix	trans_matrix;

	trans_matrix = ft_build_trans_matrix(x, y, z);
	trans_matrix = ft_inverse_matrix(&trans_matrix);
	tmp = ft_matrix_mult(trans_matrix, ft_tuple_to_matrix(p));
	return (ft_matrix_to_tuple(tmp));
}

/**
 * Construcción de la matriz para realizar la operación de traslación.
 * Se obtiene añadiendo a la matriz identidad las unidades `x`, `y` y `z`
 * que queramos desplazar un punto en las tres primeras posiciones de la 
 * última columna de la matriz respectivamente.
 */
static t_matrix ft_build_trans_matrix(double x, double y, double z)
{
	t_matrix	trans_matrix;

	trans_matrix = ft_identity_matrix(4,4);
	trans_matrix.val[0][3] = x;
	trans_matrix.val[1][3] = y;
	trans_matrix.val[2][3] = z;
	trans_matrix.val[3][3] = 1;
	return (trans_matrix);
}