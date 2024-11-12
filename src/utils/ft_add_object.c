/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:27:11 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:27:14 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 #include "../../include/mini_rt.h"

static int	ft_fill_new_obj(t_oitem *new, t_omodel o_to_add, int o_type, \
	int color);
static int	ft_add_sphere(void **o_struct, t_sphere sp);


int	ft_add_obj(t_oitem **o_list, t_omodel o_to_add, int o_type, int color)
{
	int		status;
	t_oitem	*tmp;
	t_oitem	*new;

	status = EXIT_SUCCESS;
	tmp = *o_list;
	new = (t_oitem *)malloc(sizeof (t_oitem));
	if (!new || ft_fill_new_obj(new, o_to_add, o_type, color))
		status = EXIT_FAILURE;
	else if (NULL == *o_list)
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


static int	ft_fill_new_obj(t_oitem *new, t_omodel o_to_add, int o_type, \
	int color)
{
	int	status;

	new->obj_id = ft_obj_id_assignment();
	new->obj_type = o_type;
	new->material = ft_default_material(color);
	new->prev = NULL;
	new->next = NULL;
	if (SPHERE == o_type)
		status = ft_add_sphere(&(new->obj_struct), o_to_add.sp);
	if (PLANE == o_type)
		status = 1;
	if (CYLINDER == o_type)
		status = 1;
	return (status);
}


static int	ft_add_sphere(void **o_struct, t_sphere sp)
{
	int			status;
	t_sphere	*sphere;	

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (NULL == sphere)
		status = EXIT_FAILURE;
	else
	{
		sphere->origin = sp.origin;
		sphere->radius = sp.radius;
		sphere->transformations_matrix = sp.transformations_matrix;
		*o_struct = (void *)sphere;
		status = EXIT_SUCCESS;
	}
	return (status);
}
*/