/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:26:42 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:26:46 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/**
 * Devuelve el punto resultante de mover `ray.origin` (punto)
 * en la dirección `ray.direction` (vector) la distancia `position`.
 * @return Tupla tipo punto con el punto resultante.
*/
t_tuple	ft_rc_position(t_ray ray, double position)
{
	t_tuple	result;

	ft_tuples_check(ray.origin.w + ray.direction.w);
	result = ray.direction;
	ft_scalar_mult(&(result), position, VECTOR);
	result = ft_add_tuples(ray.origin, result);
	return (result);
}
