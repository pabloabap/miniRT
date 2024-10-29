//CABECERA
#include "../../include/mini_rt.h"

/**
 * Construye la estructura de un objeto esfera.
 * @param center Coordenadas X, Y, Z del cento de la circunferencia.
 * @param radius Radio de la circunferencia.
 * Transformations_matrix almacenará la matriz con las transformaciones
 * aplicadas sober la esfera. Esto es de utilidad para el calculo de
 * sombras y aplicación de matrices inversas para el paso de 
 * coordenadas objeto a globales.
 * @return Retorna la estructura `t_sphere`
 */
t_sphere ft_build_sphere(t_tuple center, double radius)
{
	t_sphere	sphere;

	sphere.origin = center;
	sphere.radius = radius;
	sphere.transformations_matrix = ft_identity_matrix(4,4);
	return (sphere);
}