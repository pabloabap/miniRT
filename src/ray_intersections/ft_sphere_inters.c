/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere_inters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:26:51 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:26:57 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

double			ft_discriminant(double *v);
static void		ft_fill_v(t_ray ray, t_sphere sp, double *v);

/**
 * Añade los puntos de intersección del rayo `ray` con la esfera `sphere`
 * en la lista `i_list`.
 */
void	ft_sphere_inters(t_ray ray, t_oitem *sphere, t_ray_inters **i_list)
{
	double	v[3];
	double	tan[2];

	ft_fill_v(ray, *(t_sphere *)(sphere->obj_struct), &v[0]);
	tan[0] = (-v[1] - sqrt(ft_discriminant(&v[0]))) / (2 * v[0]);
	tan[1] = (-v[1] + sqrt(ft_discriminant(&v[0]))) / (2 * v[0]);
	if (!isnan(tan[0]))
		ft_add_inters_sorted(i_list, tan[0], sphere);
	if (!isnan(tan[1]) && (!isnan(tan[0]) || tan[0] != tan[1]))
		ft_add_inters_sorted(i_list, tan[1], sphere);
}

/**
 * Define en que punto intersecciona `ray`y `sphere`.
 * @return Discriminante.
 */
double	ft_discriminant(double *v)
{
	return (v[1] * v[1] - 4 * v[0] * v[2]);
}

/**
 * Rellena `v` con los valores constantes utilizados en las fórmulas
 * para hayar el discriminante y la intersección de rayo con circunferencia.
 * 
 * @param ray Estructura con información del rayo.
 * @param sphere Estructura con información de la esfera.
 * @param v Punteor a array de 3 double que almacenarán los valores constantes
 * 			requeridos en la operaciones de intersección.
 * @return Nada. Actualiza los valores de `v`a través del puntero.
 */
static void	ft_fill_v(t_ray ray, t_sphere sp, double *v)
{
	t_tuple	v_sp_to_ray;

	v_sp_to_ray = ft_sub_tuples(ray.origin, sp.origin);
	v[0] = ft_dot(ray.direction, ray.direction);
	v[1] = 2 * ft_dot(ray.direction, v_sp_to_ray);
	v[2] = ft_dot(v_sp_to_ray, v_sp_to_ray) - (sp.radius * sp.radius);
}
