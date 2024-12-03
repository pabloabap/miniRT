/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:00:12 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/11/20 18:00:14 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' \
			|| c == '\f' || c == '\v');
}

int	skip_num(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '+' || line[i] == '-')
		i++;
	while (('0' <= line[i] && line[i] <= '9') || line[i] == '.')
		i++;
	while (is_space(line[i]))
		i++;
	return (i);
}

int	skip_vec(char *line)
{
	int	i;

	i = 0;
	while (line[i] && !is_space(line[i]) && line[i] != '\n')
		i++;
	while (is_space(line[i]))
		i++;
	return (i);
}

t_tuple	read_vec(char *line)
{
	double	x;
	double	y;
	double	z;
	t_tuple	vec;

	if (is_vector(line))
		parsing_error(VEC_FORMAT);
	x = ft_atod(line);
	line += skip_num(line) + 1;
	y = ft_atod(line);
	line += skip_num(line) + 1;
	z = ft_atod(line);
	vec = ft_build_tuple(x, y, z, VECTOR);
	return (vec);
}

t_tuple	read_point(char *line)
{
	double	x;
	double	y;
	double	z;
	t_tuple	point;

	if (is_vector(line))
		parsing_error(POINT_FORMAT);
	x = ft_atod(line);
	line += skip_num(line) + 1;
	y = ft_atod(line);
	line += skip_num(line) + 1;
	z = ft_atod(line);
	point = ft_build_tuple(x, y, z, POINT);
	return (point);
}
