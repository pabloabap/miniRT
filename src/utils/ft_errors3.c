/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:39 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/12/03 14:34:40 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	parsing_error(int code)
{
	ft_putstr_fd("Error\n", 2);
	if (code == EXTRA_OBJ)
		ft_putstr_fd("A C y L no se pueden repetir\n", 2);
	if (code == EXTRA_PARAM)
		ft_putstr_fd("Extra parameter detected\n", 2);
	if (code == POINT_FORMAT)
		ft_putstr_fd("Formato de punto incorrecto\n", 2);
	if (code == VEC_FORMAT)
		ft_putstr_fd("Formato de vector incorrecto\n", 2);
	if (code == COLOR_FORMAT)
		ft_putstr_fd("Formato de color incorrecto\n", 2);
	if (code == FALSE_OBJECT)
		ft_putstr_fd("Objeto no reconocido\n", 2);
	if (code == FD_ERROR)
		ft_putstr_fd("File descriptor invalido\n", 2);
	exit (code);
}

/**
 * Comprueba que el input tiene definidos la camara. la luz y la luz ambiente.
 */
void	ft_empty_mandatory_items_check(t_scene *scene)
{
	if (NULL == scene->camera)
	{
		ft_putendl_fd("Error\nMissing camera params", 2);
		exit(PARSING_ERROR);
	}
	if (NULL == scene->light)
	{
		ft_putendl_fd("Error\nMissing light params", 2);
		exit(PARSING_ERROR);
	}
	if (NULL == scene->ambient_light)
	{
		ft_putendl_fd("Error\nMissing ambient params", 2);
		exit(PARSING_ERROR);
	}
}

/**
 * Comprueba que el ratio de brillo de la luz y de la luz ambiente estén en
 * el rango 0 a 1 incluidos.
 */
void	ft_check_brightness(double brightness)
{
	if (brightness < 0 || brightness > 1)
	{
		ft_putstr_fd("Error\nEl ratio de luminosidad tiene que estar en ", 2);
		ft_putendl_fd("el intervalo 0.0 - 1.0 para luz y luz ambiente.", 2);
		exit(PARSING_ERROR);
	}
}

/**
 * Comprueba que los parametros `r`, `g` y `b` de un color estén en el rango 
 * [0 - 255].
 */
void	ft_check_color(int r, int g, int b)
{
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
	{
		ft_putstr_fd("Error\nParametros RGB de color fuera ", 2);
		ft_putendl_fd("del rango [0 - 255].", 2);
		exit(PARSING_ERROR);
	}
}
