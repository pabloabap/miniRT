// CABECERA

#include "mini_rt.h"

/**
 * Comprueba si entre un punto de la escena y punto de luz hay objetos 
 * intermedios.
 * @param scene Estructura con toda la información de la escena.
 * @param point tupla con las coordenadas del punto de la escena que
 * 		queremos consultar si está sombreado.
 * @return	`1` (true) si está sombreado o `0` (false) si no.
 */
int	ft_is_shadowed(t_scene scene, t_tuple point)
{
	t_tuple	vec_v;
	double	distance;
	t_tuple	direction_v;
	t_ray	r;
	t_ray_inters	*ray_inters;

	vec_v = ft_sub_tuples(scene.light->position, point);
	distance = ft_magnitude(vec_v);
	direction_v = ft_normalize(vec_v);
	r.origin = point;
	r.direction = direction_v;
	ray_inters = NULL;
	ft_detect_ray_inters(scene.objs_list, &(ray_inters), r);
	if (ft_identify_hit(ray_inters) \
		&& ft_get_hit(ray_inters)->inter_point < distance)
		return(ft_free_ray_inters_list(ray_inters), 1);
	else
		return(ft_free_ray_inters_list(ray_inters), 0);

}
