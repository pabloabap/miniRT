// CABECERA

#include "../include/mini_rt.h"
int main(void)
{
	t_ray		r;
	t_point_light light;
	t_omodel	model;
	t_oitem		*o_list = NULL;
	t_tuple		wall_point;
	t_canvas	canvas;
	t_ray_inters *i_list = NULL;
	int			x;
	int			y;
	int			x_world;
	int			y_world;
	int			z_wall;

	canvas.mlx_init = mlx_init();
	canvas.mlx_win = mlx_new_window(canvas.mlx_init, WIDTH, HEIGHT, "miniRT");
	canvas.img = mlx_new_image(canvas.mlx_init, WIDTH, HEIGHT);
	canvas.img_addr = mlx_get_data_addr(canvas.img, &(canvas.bpp), &(canvas.line_bytes), &(canvas.endian));
	x = 0;
	y = 0;
	z_wall = 100;
	r.origin = ft_build_tuple(0, 0, 0, POINT);
	light = ft_build_light(ft_build_tuple(30,30,-10, POINT), 0.4);	
	int k = 0;
	model.sp = ft_build_sphere(ft_build_tuple(0,0,50,POINT), 40);
	model.sp.transformations_matrix = ft_matrix_translation(model.sp.transformations_matrix, 0, 0, 20);
	ft_add_obj(&o_list, model, SPHERE, ft_create_trgb(0,255,255*0.2,255));	
	while (k < 20)
	{
		o_list->material.ambient = k * 0.05;
		o_list->material.diffuse = k * 0.05;
		o_list->material.specular = k * 0.05;
		//o_list->material.shininess -= 1;
		while (y < HEIGHT)
		{
			y_world = HEIGHT / 2 - y;
			while (x < WIDTH)
			{
				x_world = - WIDTH / 2 + x;
				wall_point = ft_build_tuple(x_world, y_world, z_wall, POINT);
				r.direction = ft_normalize(ft_sub_tuples(wall_point, r.origin));
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
					printf("t: %f\n", ft_get_hit(i_list)->inter_point);
					printf("R.ORIGIN - ");
					ft_print_tuple(r.origin);
					printf("DIRECTION - ");
					ft_print_tuple(r.direction);
					printf("DIRECTION2 - ");
					ft_print_tuple(direction2);
					printf("HIT_POINT - ");
					ft_print_tuple(h_point);
					normal = ft_sp_normal_at(*(t_sphere*)o_list->obj_struct, h_point);
					printf("NORMAL - ");
					ft_print_tuple(normal);
					eye = ft_negate_tuple(ft_normalize(direction2));
					printf("EYE - ");
					ft_print_tuple(eye);
					double l =  ft_lighting(o_list->material, light, h_point, eye, normal);
					printf("LIGHTING: %f\n", l);
					ft_mlx_pixel_put(&canvas, x, y, ft_create_trgb(0, ft_get_r(color) * l,ft_get_g(color)*l, ft_get_b(color)*l));
				}
				i_list = NULL;
				x ++;
			}
			x = 0;
			y ++;
		}
		mlx_put_image_to_window(canvas.mlx_init, canvas.mlx_win, canvas.img, 0, 0);
		x = 0;
		y = 0;
		k ++;
		ft_putstr_fd("ESFERA", 2);
		ft_putnbr_fd(k, 2);
		ft_putchar_fd('\n', 2);
	}
	return (0);
}