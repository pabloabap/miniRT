/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:19:41 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:19:46 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/**
 * Crea el entero que identifica el color recibido 
 * por los parametros, 4 parametros que representan 1byte, 8bits,
 * rango de númeors de 0 a 255.
 * @param t Transparencia.
 * @param r Intendidad de color rojo.
 * @param g Intendidad de color verde.
 * @param b Intendidad de color azul.
 * @return Número entero que representa el color. 
 */
int	ft_create_trgb(unsigned char t, unsigned char r, unsigned char g, \
	unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

/**
 * Obtiene la transparencia del color recibido.
 * @param trgb Entero que representa el color.
 * @return Valor de la transparencia del color.
 */
unsigned char	ft_get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

/**
 * Obtiene el rojo del color recibido.
 * @param trgb Entero que representa el color.
 * @return Valor del color rojo del color.
 */
unsigned char	ft_get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

/**
 * Obtiene el verde del color recibido.
 * @param trgb Entero que representa el color.
 * @return Valor del color verde del color.
 */
unsigned char	ft_get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

/**
 * Obtiene el azul del color recibido.
 * @param trgb Entero que representa el color.
 * @return Valor del color azul del color.
 */
unsigned char	ft_get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}
