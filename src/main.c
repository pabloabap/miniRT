// CABECERA

#include "../include/mini_rt.h"

int main(void)
{
	t_tuple	p;
	t_tuple	p2;
	t_tuple	v;
	void		*mlx;
	t_canvas	canvas;
	void		*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "miniRT");
	canvas.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	canvas.img_addr = mlx_get_data_addr(canvas.img, &(canvas.bpp), &(canvas.line_bytes), &(canvas.endian));
	p.x = 0;
	p.y = 0;
	p.z = 0;
	p.w = 1;
	v.x = 0;
	v.y = 100;
	v.z = 0;
	v.w = 0;
	
	ft_add_tuples(&p, v);
	int color;
	int i = 0;

	color = ft_create_trgb(0, 255, 0, 0);
	while (i < 13)
	{
		//printf("x:%f, y:%f z:%f\n", p2.x, p2.y, p2.z);
		p2 = ft_tuple_rotation(p, Z, - 360/12 * (i + 1));
		ft_mlx_pixel_put(&canvas, 250 + p2.x, 250 - p2.y, color);
		//p = ft_tuple_scalation(p, 10, 10, 0);
		mlx_put_image_to_window(mlx, mlx_win, canvas.img, 0, 0);
		sleep(1);
		i ++;
	}
	sleep(30);
	return (0);
}
