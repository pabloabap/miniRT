//CABECERA

#include "../../include/mini_rt.h"

/**
 * Retorna el color del punto impactado de la lista de intersecciones del rayo.
 * @param i_list Puntero al primer elemento de la lista de intersecciones de 
 * 		un rayo.
 * @param o_list Lista de objetos de la escena para obtener el color del objeto
 * 		impactado.
 * @return `int`con el codigo de color del objeto impactado.
 */
int	ft_get_hit_color(t_ray_inters *i_list, t_oitem *o_list)
{
	while (i_list && 0 == i_list->hit)
		i_list = i_list->next;
	if (0 != i_list->hit)
	{
		while (i_list->obj_id != o_list->obj_id)
			o_list = o_list->next;
		return (o_list->material.color);
	}
	return (0);
}
