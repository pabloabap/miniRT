/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lights.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:03:50 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/12/02 21:03:51 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	check_repeat(void *obj)
{
	if (obj)
		parsing_error(EXTRA_OBJ);
}

int	set_ambient(char *line, t_scene *scene)
{
	int			i;
	t_ambient	*amb;

	check_repeat(scene->ambient_light);
	amb = malloc(sizeof(t_ambient));
	i = skip_space(line);
	amb->ratio = ft_atod_val(&line[i]);
	ft_check_brightness(amb->ratio);
	i += skip_num(&line[i]);
	amb->color = read_color(&line[i]);
	i += skip_vec(&line[i]);
	scene->ambient_light = amb;
	return (check_line_end(&line[i]));
}

int	set_camera(char *line, t_scene *scene)
{
	t_camera	cam;
	int			i;
	t_tuple		to_p;

	check_repeat(scene->camera);
	i = skip_space(line);
	scene->camera = malloc(sizeof(t_camera));
	scene->camera->position_p = read_point(&line[i]);
	i += skip_vec(&line[i]);
	scene->camera->orientation_v = read_vec(&line[i]);
	ft_normalized_vec_check(scene->camera->orientation_v);
	to_p = ft_sub_tuples(scene->camera->position_p, \
		ft_negate_tuple(scene->camera->orientation_v));
	i += skip_vec(&line[i]);
	cam = ft_build_camera(HEIGHT, WIDTH, ft_atod_val(&line[i]));
	i += skip_num(&line[i]);
	cam.position_p = scene->camera->position_p;
	cam.orientation_v = scene->camera->orientation_v;
	cam.transformations_matrix = ft_matrix_view_transform(\
		cam.position_p, to_p, ft_build_tuple(0, \
			(cam.orientation_v.x != 0 || cam.orientation_v.z != 0), \
			(cam.orientation_v.y < 0) - (cam.orientation_v.y > 0), VECTOR));
	cam.inv_transform = ft_inverse_matrix(&cam.transformations_matrix);
	*(scene->camera) = cam;
	return (check_line_end(&line[i]));
}

int	check_l_color(char	*line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]) && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	set_light(char *line, t_scene *scene)
{
	t_point_light	*light;
	int				i;

	check_repeat(scene->light);
	light = malloc(sizeof(t_point_light));
	i = skip_space(line);
	light->position = read_point(&line[i]);
	i += skip_vec(&line[i]);
	light->brightness = ft_atod(&line[i]);
	ft_check_brightness(light->brightness);
	i += skip_num(&line[i]);
	if (check_l_color(&line[i]))
	{
		light->color = read_color(&line[i]);
		i += skip_vec(&line[i]);
	}
	else
		light->color = ft_create_trgb(0, 255, 255, 255);
	scene->light = light;
	return (check_line_end(&line[i]));
}
