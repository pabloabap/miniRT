/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:56:12 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/12/02 20:56:13 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	check_line_end(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]) && line[i] != '\n')
			parsing_error(EXTRA_PARAM);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	valid_char(char c)
{
	return (c == ',' || c == '.' || (c >= '0' && c <= '9') \
			|| c == '+' || c == '-' || is_space(c) || c == '\n');
}

int	check_line(char *line, int obj)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!valid_char(line[i]))
			return (-1);
		i++;
	}
	return (obj);
}

int	skip_space(char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	return (i);
}

int	skip_num2(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '-')
		i++;
	while (line[i] == '+')
		i++;
	while ((line[i] >= '0' && line[i] <= '9'))
		i++;
	return (i);
}
