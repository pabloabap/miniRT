#include "mini_rt.h"

static int	ft_fill_new_obj(t_oitem *new, int o_type, void *obj, int color)
{
	new->obj_id = ft_obj_id_assignment();
	new->obj_type = o_type;
	new->material = ft_default_material(color);
	new->prev = NULL;
	new->next = NULL;
	if (SPHERE == o_type)
    {
        obj = (t_sphere *)obj;
		new->obj_struct = obj;
        return (EXIT_SUCCESS);
    }
    if (PLANE == o_type)
	{
		obj = (t_plane *)obj;
		new->obj_struct = obj;
        return (EXIT_SUCCESS);
	}
	if (CYLINDER == o_type)
	{
		obj = (t_cylinder *)obj;
		new->obj_struct = obj;
        return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	ft_add_obj(t_oitem **o_list, int o_type, void *obj, int color)
{
	int		status;
	t_oitem	*tmp;
	t_oitem	*new;

	status = EXIT_SUCCESS;
	tmp = *o_list;
	new = (t_oitem *)malloc(sizeof (t_oitem));
	if (!new || ft_fill_new_obj(new, o_type, obj, color))
		status = EXIT_FAILURE;
	else if (!tmp)
		*o_list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (status);
}