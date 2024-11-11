#include "mini_rt.h"

static int	ft_fill_new_obj(t_oitem *new, t_omodel o_to_add, int o_type, \
	int color);
static int	ft_add_sphere(void **o_struct, t_sphere sp);


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

static int	ft_fill_new_obj(t_oitem *new, int o_type, void *obj, int color)
{
	int	status;

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
		status = 1;
	if (CYLINDER == o_type)
		status = 1;
	return (status);
}


int set_sphere(char *line, t_scene *scene)
{
    t_sphere    *sphere;
    int         i;
    int         color;

    sphere = malloc(sizeof(t_sphere));
    while (is_space(line[i]))
        i++;
    sphere->origin = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    sphere->radius = ft_atod(&line[i]);
    i += skip_num(&line[i]);
    color = read_color(&line[i]);
    ft_add_obj(&scene->objs_list, SPHERE, sphere, color);
    return (EXIT_SUCCESS);
}