//CABECERA

#include "../../include/mini_rt.h"

int	ft_render_scene()
{
	while (y < HEIGHT)
	{
		y_world = HEIGHT / 2 - y;
		while (x < WIDTH)
		{
			x_world = - WIDTH / 2 + x;
			wall_point = ;
			r.direction = ft_normalize(ft_sub_tuples( \
				ft_build_tuple(x_world, y_world, z_wall, POINT), r.origin));
			t_oitem *tmp = o_list;
			while (tmp)
			{
				ft_sphere_inters(r, *(tmp), &i_list);
				tmp = tmp->next;
			}
			if (1 == ft_identify_hit(i_list))
			{
				t_tuple h_point;
				t_tuple direction2;
				t_tuple eye;
				t_tuple normal;
				int color = ft_get_hit_color(i_list, o_list);

				direction2 = r.direction;
				ft_scalar_mult(&direction2, ft_get_hit(i_list)->inter_point, VECTOR);
				h_point = ft_add_tuples(r.origin, direction2);
				normal = ft_sp_normal_at(*(t_sphere*)o_list->obj_struct, h_point);
				eye = ft_negate_tuple(ft_normalize(direction2));
				double l =  ft_lighting(o_list->material, light, h_point, eye, normal);
				ft_mlx_pixel_put(&canvas, x, y, ft_create_trgb(0, ft_get_r(color) * l,ft_get_g(color)*l, ft_get_b(color)*l));
			}
			i_list = NULL;
			x ++;
		}
		x = 0;
		y ++;
	}
}

static int	ft_inters_tracing()
{
	if (ft_identify_hit(i_list))
	{
		t_tuple h_point;
		t_tuple direction2;
		t_tuple eye;
		t_tuple normal;
		int color = ft_get_hit_color(i_list, o_list);

		direction2 = r.direction;
		ft_scalar_mult(&direction2, ft_get_hit(i_list)->inter_point, VECTOR);
		h_point = ft_add_tuples(r.origin, direction2);
		normal = ft_sp_normal_at(*(t_sphere*)o_list->obj_struct, h_point);
		eye = ft_negate_tuple(ft_normalize(direction2));
		double l =  ft_lighting(o_list->material, light, h_point, eye, normal);
		ft_mlx_pixel_put(&canvas, x, y, ft_create_trgb(0, ft_get_r(color) * l,ft_get_g(color)*l, ft_get_b(color)*l));
	}
}