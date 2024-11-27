//CABECERA

#include "mini_rt.h"

static int ft_exit_mlx(t_canvas *canvas);
static int ft_keyboard_hooks(int keycode, t_scene *scene);

void	ft_mlx_hook_mng(t_scene *scene)
{
	mlx_hook(scene->canvas->mlx_win, ON_DESTROY, NO_EVENT, ft_exit_mlx, scene->canvas);
	mlx_hook(scene->canvas->mlx_win, ON_KEYPRESS, KEYPRESS, ft_keyboard_hooks, scene);
}

static int ft_exit_mlx(t_canvas *canvas)
{
	mlx_destroy_image(canvas->mlx_init, canvas->img);
	mlx_destroy_window(canvas->mlx_init, canvas->mlx_win);
	exit(0);
	return (0);
}

static int ft_keyboard_hooks(int keycode, t_scene *scene)
{
	printf("%i\n", keycode);
	if (keycode == ESC)
		ft_exit_mlx(scene->canvas);
	/* else if (keycode == UP_ARROW)
	{
		reset_camera(scene, ft_build_tuple(0,1,0,VECTOR));
		ft_render_scene(scene);
		printf("ENTRA!\n");
		mlx_put_image_to_window(scene->canvas->mlx_init, \
		scene->canvas->mlx_win, scene->canvas->img, 0, 0);
	}
	else if (keycode == DOWN_ARROW)
	{
		reset_camera(scene, ft_build_tuple(0.0,0.0,1.0,VECTOR));
		ft_render_scene(scene);
		printf("ENTRA2!\n");
		mlx_put_image_to_window(scene->canvas->mlx_init, \
		scene->canvas->mlx_win, scene->canvas->img, 0, 0);
	} */
	return (0);
}