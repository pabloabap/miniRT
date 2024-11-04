//CABECERA
#include "../../include/mini_rt.h"

/** Haya la normal sobre un punto especifico en la superficie de una esfera.
 * @param sp Esfera a la que pertenece el punto para obtener la matriz con las 
 * 	transformaciones aplicadas a la esfera.
 * @param surface_point `t_tuple`con las coordenadas del punto de la superfice en
 * 	en el espacio global.
 * @return Vector normal del punto en el espacio global.
 */
t_tuple	ft_sp_normal_at(t_sphere sp, t_tuple surface_point)
{
	t_tuple	obj_point;
	t_tuple	obj_normal;
	t_tuple	world_normal;

	ft_sp_normal_at_check(surface_point.w);
	obj_point = ft_matrix_to_tuple(ft_matrix_mult(\
		ft_inverse_matrix(&(sp.transformations_matrix)), \
		ft_tuple_to_matrix(surface_point)));
	obj_normal = ft_build_tuple(obj_point.x, obj_point.y, obj_point.z, VECTOR);
	world_normal = ft_matrix_to_tuple(ft_matrix_mult(ft_matrix_transpos(\
		ft_inverse_matrix(&sp.transformations_matrix)), \
		ft_tuple_to_matrix(obj_normal)));
	world_normal.w = 0;
	return (ft_normalize(world_normal));
}
