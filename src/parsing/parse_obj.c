/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:02:01 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/11/20 18:02:03 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	ft_fill_new_obj(t_oitem *new, int o_type, void *obj);

/**
 * Añade una nueva estructura al final de una lista de objetos.
 * @param scene Puntero a la escena para acceder a sus elementos necesarios.
 * @param o_type Elemento de la enumeracion `t_element_type` que indica
 * 	el tipo de objeto (SPHERE, PLANE, CYLINDER) que está recibiendo la 
 * 	función para procesarlo según corresponda.
 * @param obj Puntero a objeto a añadir.
 * @param color Entero con el código de color del objeto recibido.
 * @return Entero con el resultado de salida de la función.
 */
int	ft_add_obj(t_scene *scene, int o_type, void *obj, int color)
{
	int		status;
	t_oitem	*tmp;
	t_oitem	*new;

	status = EXIT_SUCCESS;
	tmp = scene->objs_list;
	new = (t_oitem *)malloc(sizeof (t_oitem));
	if (!new || ft_fill_new_obj(new, o_type, obj))
		status = EXIT_FAILURE;
	else if (!tmp)
		scene->objs_list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	new->material = ft_default_material(color);
	return (status);
}

/**
 * Constructor de una nueva estructura `t_oitem`para incluirla en la
 * lista de objetos.
 * @param new Puntero a `t_oitem` para darle contenido.
 * @param o_type Elemento de la enumeracion `t_element_type` que indica
 * 	el tipo de objeto (SPHERE, PLANE, CYLINDER) que está recibiendo la 
 * 	función para procesarlo según corresponda.
 * @param obj Puntero a objeto a añadir.
 * @return Entero con el resultado de salida de la función.
 */
static int	ft_fill_new_obj(t_oitem *new, int o_type, void *obj)
{
	new->obj_id = ft_obj_id_assignment();
	new->obj_type = o_type;
	new->prev = NULL;
	new->next = NULL;
	if (SPHERE == o_type || PLANE == o_type || CYLINDER == o_type)
	{
		if (SPHERE == o_type)
			obj = (t_sphere *)obj;
		else if (PLANE == o_type)
			obj = (t_plane *)obj;
		else if (CYLINDER == o_type)
			obj = (t_cylinder *)obj;
		new->obj_struct = obj;
		ft_set_transformations_matrix(new, o_type);
		new->inv_transform = ft_inverse_matrix(&new->transformations_matrix);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
