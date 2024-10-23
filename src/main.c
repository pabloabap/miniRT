// CABECERA

#include "../include/mini_rt.h"

int main(void)
{
	t_ray		r;
	t_sphere	s;
	t_sphere	s2;
	t_sphere	collection[2];
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
	s.obj_id = ft_obj_id_assignment();
	s.obj_type = SPHERE;
	s.color = ft_create_trgb(0, 255, 0, 0);
	s.origin = ft_build_tuple(0, 2, 5, POINT);
	s.radius = 1;
	s2.obj_id = ft_obj_id_assignment();
	s2.obj_type = SPHERE;
	s2.color = ft_create_trgb(0, 0, 255, 0);
	s2.origin = ft_build_tuple(0, 0, 3, POINT);
	s2.radius = 1;
	collection[0] = s;
	collection[1] = s2;
	int i = 0; 
	double j = 0.2;

	while (j >= -2)
	{
		while (i < 100)
		{
			//canvas.img = mlx_new_image(canvas.mlx_init, WIDTH, HEIGHT);
			//canvas.img_addr = mlx_get_data_addr(canvas.img, &(canvas.bpp), &(canvas.line_bytes), &(canvas.endian));
			while (y < HEIGHT)
			{
				y_world = HEIGHT / 2 - y;
				while (x < WIDTH)
				{
					x_world = - WIDTH / 2 + x;
					wall_point = ft_build_tuple(x_world, y_world, z_wall, POINT);
					r.direction = ft_normalize(ft_sub_tuples(wall_point, r.origin));
					ft_sphere_inters(r, s, &i_list);
					ft_sphere_inters(r, s2, &i_list);
					if (1 == ft_identify_hit(i_list))
						ft_mlx_pixel_put(&canvas, x, y, collection[ft_get_hit(i_list)->obj_id].color);
					i_list = NULL;
					x ++;
				}
				x = 0;
				y ++;
			}
			mlx_put_image_to_window(canvas.mlx_init, canvas.mlx_win, canvas.img, 0, 0);
			// s.origin = ft_tuple_scalation(s.origin, 0, 0, 1.05);
			// El escalado translada tuplas, pero por multiplicación, traslation lo hace sumando unidades.
			//s.origin = ft_tuple_scalation(s.origin, 0, 0, 0.5);
			//___Operacion de transformacion sobre un objeto es equivalente a aplicar la inversa de la transformacion al rayo.
			//s.origin = ft_tuple_translation(s.origin, 0, 0, -0.5);
			//r.origin = ft_tuple_inverse_translation(r.origin, 0, 0, -0.5);
			// s.origin = ft_tuple_rotation(s.origin, Z, 20);
			/* if (i % 2)
				s.color = ft_create_trgb(0, 0, 255, 0);
			else
				s.color = ft_create_trgb(0, 255, 0, 0); */
			y = 0;
			i++;
			if (i % 4 == 0)
				sleep(1);
			sleep(1);
		}
		i = 0;
		j *= -1;
	}
	sleep(10);
	return (0);
}
