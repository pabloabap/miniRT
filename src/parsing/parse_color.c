/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:03:24 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/11/20 18:03:26 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	read_color(char *line)
{
	int	c;
	int	r;
	int	g;
	int	b;

	if (is_vector(line))
		parsing_error(COLOR_FORMAT);
	r = ft_atoi(line);
	line += skip_num(line) + 1;
	g = ft_atoi(line);
	line += skip_num(line) + 1;
	b = ft_atoi(line);
	ft_check_color(r, g, b);
	c = ft_create_trgb(0, r, g, b);
	return (c);
}

int	set_rgb(int r, int g, int b)
{
	return (255 << 24 | r << 16 | g << 8 | b);
}

int	get_red(int c)
{
	return ((c >> 16) & 0xFF);
}

int	get_green(int c)
{
	return ((c >> 8) & 0xFF);
}

int	get_blue(int c)
{
	return (c & 0xFF);
}
