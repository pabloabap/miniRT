/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_material.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:29:17 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:29:20 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/** Pendiente de completar. Son atributos de un objeto
 * para calcular como le afecta la luz.
 */
t_material	ft_default_material(int color)
{
	t_material	m;

	m.color = color;
	m.ambient = 0.5;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 1.0;
	return (m);
}
