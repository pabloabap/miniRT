//CABECERA

#include "../../include/mini_rt.h"
void	ft_identify_hit(t_ray_inters *i_list)
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
}