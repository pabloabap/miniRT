//CABECERA

#include "../include/mini_rt.h"

/** Imprime los valores de las estructuras de una lista de intersecciones */
void	ft_print_i_list(t_ray_inters *i_list)
{
	while (i_list)
	{
		printf("====\nHIT: %i, INTER_POINT: %f, OBJ_ID: %i, PREV: %p, NEXT: %p\n", \
		i_list->hit, i_list->inter_point, i_list->obj_id, i_list->prev, i_list->next);
		i_list = i_list->next;
	}
}