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
 * Función que normaliza el color de la escala 0.0 - 255.0 a 0.0 - 1.0
 * para calcular los ratios de luminosidad.
 * @param color Entero con el codigo de color a normalizar.
 * @return `t_tuple` de tipo COLOR con los colores RGB normalizados.
 */
t_tuple	ft_normalize_color(int color)
{
	return (ft_build_tuple(ft_get_r(color) / 255.0, ft_get_g(color) / 255.0, \
		ft_get_b(color) / 255.0, COLOR));
}
