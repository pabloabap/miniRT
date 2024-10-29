// CABECERA

#include "../include/mini_rt.h"

int main(void)
{
	t_ray		r;
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
	for (size_t i = 0; i < 1; i++)
	{
		model.sp = ft_build_sphere(ft_build_tuple(0,0,50,POINT), 10);
		model.sp.transformations_matrix = ft_matrix_shearing(ft_matrix_scalation(ft_identity_matrix(4, 4), 0.5,1,1), X, Y, 1);
		ft_print_matrix(model.sp.transformations_matrix);
		if (i % 2 == 0)
			ft_add_obj(&o_list, model, SPHERE, ft_create_trgb(0,255,0,0));	
		else if (i % 3 == 0)
			ft_add_obj(&o_list, model, SPHERE, ft_create_trgb(0,0,255,0));	
		else
			ft_add_obj(&o_list, model, SPHERE, ft_create_trgb(0,0,0,255));	
	}	
	printf("\n==============\n");
	ft_print_matrix(ft_inverse_matrix(&((t_sphere *)(o_list->obj_struct))->transformations_matrix));
	//canvas.img = mlx_new_image(canvas.mlx_init, WIDTH, HEIGHT);
	//canvas.img_addr = mlx_get_data_addr(canvas.img, &(canvas.bpp), &(canvas.line_bytes), &(canvas.endian));
	//r.direction = ft_tuple_inverse_scalation(r.direction, 200, 1, 1);
	//r.direction = ft_tuple_inverse_scalation(r.direction, 1, 1, 0.5);
	//s2.origin = ft_tuple_shearing(s2.origin, Y, X, 1);
	//s3.origin = ft_tuple_translation(s3.origin, 10, 1, 1);
	//s2.origin = ft_tuple_scalation(s2.origin, 10, 1, 1);
	//s.origin = ft_tuple_scalation(s.origin, 1, 0.5, 1);
	//s.origin = ft_tuple_scalation(s.origin, 1, 0.5, 1);
	// r.origin = ft_tuple_inverse_translation(r.origin, 200, 0, 0);
	r.origin = ft_matrix_to_tuple(ft_matrix_mult(\
		ft_inverse_matrix(&((t_sphere *)(o_list->obj_struct))->transformations_matrix), \
		ft_tuple_to_matrix(r.origin)));
	while (y < HEIGHT)
	{
		y_world = HEIGHT / 2 - y;
		while (x < WIDTH)
		{
			x_world = - WIDTH / 2 + x;
			wall_point = ft_build_tuple(x_world, y_world, z_wall, POINT);
			r.direction = ft_normalize(ft_sub_tuples(wall_point, r.origin));
			r.direction = ft_matrix_to_tuple(ft_matrix_mult(\
				ft_inverse_matrix(&((t_sphere *)(o_list->obj_struct))->transformations_matrix), \
				ft_tuple_to_matrix(r.direction)));
			t_oitem *tmp = o_list;
			while (tmp)
			{
				ft_sphere_inters(r, *(tmp), &i_list);
				tmp = tmp->next;
			}
			if (1 == ft_identify_hit(i_list))
				ft_mlx_pixel_put(&canvas, x, y, ft_get_hit_color(i_list, o_list));
			i_list = NULL;
			x ++;
		}
		x = 0;
		y ++;
	}
	mlx_put_image_to_window(canvas.mlx_init, canvas.mlx_win, canvas.img, 0, 0);
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
	printf("ESPERANDO...\n");
	sleep(10);
	return (0);
}

/*
int main(void)
{
	t_sphere	s;
	t_tuple		norm_vector;
	t_matrix	transformation_matrix;

	s = ft_build_sphere(ft_build_tuple(0,0,0,POINT), 1);
	s.transformations_matrix = ft_matrix_mult(ft_matrix_scalation(ft_identity_matrix(4,4), 1, 0.5, 1), \
		 ft_matrix_rotation(ft_identity_matrix(4,4), Z, 180/5));
	//transformation_matrix = ft_matrix_translation(ft_identity_matrix(4,4), 0, 1, 0);
	printf("TRANSFORMATION MATRIX:\n");
	ft_print_matrix(transformation_matrix);
	norm_vector = ft_sp_normal_at(ft_build_tuple(0, sqrt(2)/2, -sqrt(2)/2, POINT), s.transformations_matrix);
	printf("X:%f, Y:%f, Z:%f, W:%f\n", norm_vector.x, norm_vector.y, norm_vector.z, norm_vector.w);
	//norm_vector = ft_sp_normal_at(s, ft_build_tuple(0, 1, 0, POINT));
	//printf("X:%f, Y:%f, Z:%f, W:%f\n", norm_vector.x, norm_vector.y, norm_vector.z, norm_vector.w);
	//norm_vector = ft_sp_normal_at(s, ft_build_tuple(0, 0, 1, POINT));
	//printf("X:%f, Y:%f, Z:%f, W:%f\n", norm_vector.x, norm_vector.y, norm_vector.z, norm_vector.w);
	//norm_vector = ft_sp_normal_at(s, ft_build_tuple(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3, POINT));
	//printf("X:%f, Y:%f, Z:%f, W:%f\n", norm_vector.x, norm_vector.y, norm_vector.z, norm_vector.w);
	return (0);
}
*/