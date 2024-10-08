// CABECERA

#include "../include/mini_rt.h"

int main(void)
{
	void		*mlx;
	t_canvas	canvas;
	void		*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "miniRT");
	canvas.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	canvas.img_addr = mlx_get_data_addr(canvas.img, &(canvas.bpp), &(canvas.line_bytes), &(canvas.endian));

	int x = 0, y = 0, color = 0;
	while (y < HEIGHT)
	{
		while(x < WIDTH)
		{
			color = ft_create_trgb(0, (x / 2) % 255, (x * y / 2) % 255, (x * x / 2) % 255);
			ft_mlx_pixel_put(&canvas, x, y, color);
			x ++;
		}
		x = 0;
		printf ("LINEA: %d COMPLETADA, COLOR %X\n", y, color);
		y ++;
	}
	mlx_put_image_to_window(mlx, mlx_win, canvas.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}