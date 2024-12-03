/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:44:55 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/12/02 21:44:57 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	ft_fill_v_cy(t_ray ray, t_cylinder cy, double *v)
{
	v[0] = ray.direction.x * ray.direction.x + \
			ray.direction.z * ray.direction.z;
	v[1] = 2 * (ray.origin.x * ray.direction.x + \
			ray.origin.z * ray.direction.z);
	v[2] = ray.origin.x * ray.origin.x + \
			ray.origin.z * ray.origin.z - \
			((cy.diameter * cy.diameter) / 4.0);
}

int	check_height(t_ray ray, double t, t_cylinder cy)
{
	t_tuple	point;

	point = ft_rc_position(ray, t);
	if (point.y > cy.height / 2.0 || point.y < -cy.height / 2.0)
		return (0);
	return (1);
}

void	ft_cylinder_caps(t_ray ray, t_oitem *cy, t_ray_inters **i_list)
{
	t_cylinder	*cy_obj;
	double		t;
	t_tuple		point;
	double		cap_y;

	cy_obj = (t_cylinder *)(cy->obj_struct);
	cap_y = cy_obj->height / 2.0;
	if ((fabs(ray.direction.y) < 1e-5))
		return ;
	t = (cap_y - ray.origin.y) / ray.direction.y;
	point = ft_rc_position(ray, t);
	if (sqrt((point.x * point.x) + (point.z * point.z)) \
			<= cy_obj->diameter / 2.0)
		ft_add_inters_sorted(i_list, t, cy);
	t = (-cap_y - ray.origin.y) / ray.direction.y;
	point = ft_rc_position(ray, t);
	if (sqrt((point.x * point.x) + (point.z * point.z)) \
			<= cy_obj->diameter / 2.0)
		ft_add_inters_sorted(i_list, t, cy);
}

void	ft_cylinder_inters(t_ray ray, t_oitem *cy, t_ray_inters **i_list)
{
	double		v[3];
	double		tan[2];
	t_cylinder	*cyl;

	cyl = (t_cylinder *)(cy->obj_struct);
	ft_fill_v_cy(ray, *(t_cylinder *)(cy->obj_struct), &v[0]);
	tan[0] = (-v[1] - sqrt(ft_discriminant(&v[0]))) / (2 * v[0]);
	tan[1] = (-v[1] + sqrt(ft_discriminant(&v[0]))) / (2 * v[0]);
	if (!isnan(tan[0]) && check_height(ray, tan[0], *cyl))
		ft_add_inters_sorted(i_list, tan[0], cy);
	if ((!isnan(tan[1]) && (!isnan(tan[0]) || tan[0] != tan[1])) \
			&& check_height(ray, tan[1], *cyl))
		ft_add_inters_sorted(i_list, tan[1], cy);
	ft_cylinder_caps(ray, cy, i_list);
}
