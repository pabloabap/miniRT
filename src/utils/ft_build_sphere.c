//CABECERA
#include "../../include/mini_rt.h"

/**
 * Construye la estructura de un objeto esfera.
 * @param x_center Coordenada X del cento de la circunferencia.
 * @param y_center Coordenada Y del cento de la circunferencia.
 * @param z_center Coordenada Z del cento de la circunferencia.
 * @param radius Radio de la circunferencia.
 * @return Retorna la estructura `t_sphere`
 */
t_sphere ft_build_sphere(double x_center, double y_center, double z_center, \
	double radius)
{
	t_sphere	sphere;

	sphere.obj_id = ft_obj_id_assignment();
	sphere.obj_type = SPHERE;
	sphere.origin = ft_build_tuple(x_center, y_center, z_center, POINT);
	sphere.radius = radius;
	return (sphere);
}