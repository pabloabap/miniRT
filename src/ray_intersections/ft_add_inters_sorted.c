//CABECERA

#include "../../include/mini_rt.h"
static int	ft_build_new_inters(t_ray_inters **new, double inter_point, int obj_id);
static void	ft_i_list_update(t_ray_inters **i_list, t_ray_inters *tmp, t_ray_inters *new);
int	ft_add_inters_sorted(t_ray_inters **i_list, double inter_point, int obj_id)
{
	t_ray_inters	*tmp;
	t_ray_inters	*new;

	tmp = *i_list;
	ft_build_new_inters(&new, inter_point, obj_id);
	if (*i_list == NULL)
		*i_list = new;
	else
	{
		while (tmp->next && inter_point > tmp->inter_point)
			tmp = tmp->next;
		ft_i_list_update(i_list, tmp, new);
	}
	return (EXIT_SUCCESS);
}

static int	ft_build_new_inters(t_ray_inters **new, double inter_point, int obj_id)
{
	*new = (t_ray_inters *)malloc(sizeof(t_ray_inters));
	if (NULL == new)
		exit(100); //return (EXIT_FAILURE);
	(*new)->inter_point = inter_point;
	(*new)->obj_id = obj_id;
	(*new)->hit = 0;
	(*new)->prev = NULL;
	(*new)->next = NULL;
	return (EXIT_SUCCESS);
}

static void	ft_i_list_update(t_ray_inters **i_list, t_ray_inters *tmp, t_ray_inters *new)
{
	if (!tmp->next && new->inter_point > tmp->inter_point)
		{
			new->prev = tmp;
			tmp->next = new;
		}
		else
		{
			new->prev = tmp->prev;
			new->next = tmp;
			if (tmp->prev)
				tmp->prev->next = new;
			tmp->prev = new;
			if (tmp == *i_list)
				*i_list = new;				
		}
}