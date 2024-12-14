/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:07:09 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/28 11:07:44 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	set_sphere(char *line, t_scene *scene)
{
	t_sphere	*sphere;
	int			i;
	int			color;

	i = skip_space(line);
	sphere = malloc(sizeof(t_sphere));
	sphere->origin = read_point(&line[i]);
	i += skip_vec(&line[i]);
	sphere->radius = ft_atod_val(&line[i]) / 2;
	i += skip_num(&line[i]);
	color = read_color(&line[i]);
	i += skip_vec(&line[i]);
	ft_add_obj(scene, SPHERE, sphere, color);
	return (check_line_end(&line[i]));
}

int	set_cylinder(char *line, t_scene *scene)
{
	t_cylinder	*cylinder;
	int			i;
	int			color;

	i = skip_space(line);
	cylinder = malloc(sizeof(t_cylinder));
	cylinder->origin = read_vec(&line[i]);
	i += skip_vec(&line[i]);
	cylinder->nrm_vector = read_vec(&line[i]);
	ft_normalized_vec_check(cylinder->nrm_vector);
	i += skip_vec(&line[i]);
	cylinder->diameter = ft_atod_val(&line[i]);
	i += skip_num(&line[i]);
	cylinder->height = ft_atod_val(&line[i]);
	i += skip_num(&line[i]);
	color = read_color(&line[i]);
	i += skip_vec(&line[i]);
	ft_add_obj(scene, CYLINDER, cylinder, color);
	return (check_line_end(&line[i]));
}

int	set_plane(char *line, t_scene *scene)
{
	t_plane		*plane;
	int			i;
	int			color;

	i = skip_space(line);
	plane = malloc(sizeof(t_plane));
	plane->origin = read_vec(&line[i]);
	i += skip_vec(&line[i]);
	plane->nrm_vector = read_vec(&line[i]);
	ft_normalized_vec_check(plane->nrm_vector);
	i += skip_vec(&line[i]);
	color = read_color(&line[i]);
	i += skip_vec(&line[i]);
	ft_add_obj(scene, PLANE, plane, color);
	return (check_line_end(&line[i]));
}
