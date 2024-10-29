//CABECERA

#include "../../include/mini_rt.h"

/** Retorna 1 si encuentra un punto de interseccion de un rayo
 *  en una lista de impactos, o 0 si no.
 */
int	ft_identify_hit(t_ray_inters *i_list)
{
	int	hit;

	hit = 0;
	while (i_list && 0 == hit)
	{
		if (i_list->inter_point >= 0)
		{
			hit = 1;
			i_list->hit = hit;
		}
		i_list = i_list->next;
	}
	return (hit);
}