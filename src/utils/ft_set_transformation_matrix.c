//CABECERA

#include "mini_rt.h"

/**
 * Establece la matriz de transformación inicial del último objeto
 * creado, es decir, la traslación de su origen.
 * @param objs_list Puntero a la lista de objetos para recorrerla.
 * @param obj_world_origin Datos del punto de origen del nuevo objeto
 *			en las coordenadas del mundo.
 * @return Nada, actualiza el atributo `transformations_matrix` del
 * 		último objeto de la lista de objetos.
 */
void	ft_set_transformation_matrix(t_oitem *objs_list, \
	t_tuple obj_world_origin)
{
	while (objs_list->next)
		objs_list = objs_list->next;
	objs_list->transformations_matrix = ft_matrix_translation(\
		ft_identity_matrix(4, 4), obj_world_origin.x, obj_world_origin.y, \
		obj_world_origin.z);
}
