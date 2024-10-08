// CABECERA

#include "../include/mini_rt.h"

int main(void)
{
	void		*mlx;
	t_canvas	canvas;
	void		*mlx_win;
	t_proyectil proy;
	t_env		env;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "miniRT");
	canvas.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	canvas.img_addr = mlx_get_data_addr(canvas.img, &(canvas.bpp), &(canvas.line_bytes), &(canvas.endian));
	proy.pos[X] = 0;
	proy.pos[Y] = 0;
	proy.vel[X] = 30;
	proy.vel[Y] = 30;
	env.grav[X] = 0;
	env.grav[Y] = -2;
	env.wind[X] = -1;
	env.wind[Y] = 0;

	int i = 0;
	while ((proy.pos[X] += proy.vel[X]) > 0 && (proy.pos[Y] += proy.vel[Y]) > 0)
	{
		proy.vel[X] += env.grav[X] + env.wind[X];
		proy.vel[Y] += env.grav[Y] + env.wind[Y];
		ft_mlx_pixel_put(&canvas, proy.pos[X], HEIGHT - proy.pos[Y], 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_win, canvas.img, 0, 0);
		sleep(1);
		i ++;
		printf("X: %d Y: %d\n", proy.pos[X], proy.pos[Y]);
	}
	mlx_loop(mlx);
	return (0);
}