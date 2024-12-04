/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:58:53 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/11/20 17:58:55 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	read_obj(char *line)
{
	int	i;

	i = skip_space(line);
	if (line[i] == 'A' && is_space(line[i + 1]))
		return (check_line(&line[i + 1], AMBIENT));
	if (line[i] == 'C' && is_space(line[i + 1]))
		return (check_line(&line[i + 1], CAMERA));
	if (line[i] == 'L' && is_space(line[i + 1]))
		return (check_line(&line[i + 1], LIGHT));
	if (line[i] == 's' && line[i + 1] == 'p' && is_space(line[i + 2]))
		return (check_line(&line[i + 2], SPHERE));
	if (line[i] == 'p' && line[i + 1] == 'l' && is_space(line[i + 2]))
		return (check_line(&line[i + 2], PLANE));
	if (line[i] == 'c' && line[i + 1] == 'y' && is_space(line[i + 2]))
		return (check_line(&line[i + 2], CYLINDER));
	if (line[i] == '\n')
		return (EMPTY);
	return (-1);
}

int	add_object(char *line, t_scene *scene)
{
	int	obj;
	int	i;

	obj = read_obj(line);
	i = skip_space(line);
	if (obj < 0)
		return (EXIT_FAILURE);
	if (obj == AMBIENT)
		return (set_ambient(&line[i + 1], scene));
	if (obj == CAMERA)
		return (set_camera(&line[i + 1], scene));
	if (obj == LIGHT)
		return (set_light(&line[i + 1], scene));
	if (obj == SPHERE)
		return (set_sphere(&line[i + 2], scene));
	if (obj == PLANE)
		return (set_plane(&line[i + 2], scene));
	if (obj == CYLINDER)
		return (set_cylinder(&line[i + 2], scene));
	return (EXIT_SUCCESS);
}

int	read_scene(char *path, t_scene *scene)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		parsing_error(FD_ERROR);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
		{
			if (add_object(line, scene))
				parsing_error(FALSE_OBJECT);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
