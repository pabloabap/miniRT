/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:06:49 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/11/20 18:06:53 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	is_val(char *line)
{
	int	i;

	i = 0;
	i += skip_space(line);
	if (line[i] == '-')
		i++;
	while (line[i] == '+')
		i++;
	if (!ft_isdigit(line[i]))
		return (-1);
	i += skip_num2(&line[i]);
	if (line[i] == '.')
	{
		if (!ft_isdigit(line[i + 1]))
			return (-1);
		i += skip_num2(&line[i + 1]) + 1;
	}
	if (line[i] && !is_space(line[i]) && line[i] != '\n')
		return (-1);
	return (i);
}

int	is_num(char *line, int end)
{
	int	i;

	i = skip_space(line);
	if (line[i] == '-')
		i++;
	while (line[i] == '+')
		i++;
	if (!ft_isdigit(line[i]))
		return (-1);
	i += skip_num2(&line[i]);
	if (line[i] == '.')
	{
		if (!ft_isdigit(line[i + 1]))
			return (-1);
		i += skip_num2(&line[i + 1]) + 1;
	}
	if (!end)
	{
		i += skip_space(&line[i]);
		if (line[i] != ',')
			return (-1);
	}
	else if (line[i] && !is_space(line[i]) && line[i] != '\n')
		return (-1);
	return (i);
}

int	is_vector(char *line)
{
	int	i;

	i = 0;
	if (is_num(&line[i], 0) == -1)
		return (EXIT_FAILURE);
	i += is_num(&line[i], 0) + 1;
	if (is_num(&line[i], 0) == -1)
		return (EXIT_FAILURE);
	i += is_num(&line[i], 0) + 1;
	if (is_num(&line[i], 1) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
