//CABECERA

#include "../../include/mini_rt.h"

/** Retorna el elemento impactado de la lista de intersecciones del rayo*/
t_ray_inters	*ft_get_hit(t_ray_inters *i_list)
{
	while (i_list && 0 == i_list->hit)
		i_list = i_list->next;
	if (0 == i_list->hit)
		return (NULL);
	return (i_list);
}