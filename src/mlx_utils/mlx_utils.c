// CABECERA

#include "../../include/mini_rt.h"

/**
 * Take a pointer struct with canvas details, pixel (x,y) coordinates, 
 * the color to draw the pixel and fill it in the image.
 * 
 * @param canvas	t_canvas struct with canvas details.
 * @param x			X coordinate of the pixel to draw.
 * @param x			Y coordinate of the pixel to draw.
 * @param color		color to apply to the pixel.
 * 
 * @return Nothing, data is changed directily on image via pointers.
 */
void	ft_mlx_pixel_put(t_canvas *img, int x, int y, int color)
{
	char	*dst;

	dst = img->img_addr + (y * img->line_bytes + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_prepare_canvas(t_canvas *canvas)
{
	canvas->mlx_init = mlx_init();
	ft_mlx_failure_check(canvas->mlx_init);
	canvas->mlx_win = mlx_new_window(canvas->mlx_init, WIDTH, HEIGHT, \
		"miniRT");
	ft_mlx_failure_check(canvas->mlx_win);
	canvas->img = mlx_new_image(canvas->mlx_init, WIDTH, HEIGHT);
	ft_mlx_failure_check(canvas->img);
	canvas->img_addr = mlx_get_data_addr(canvas->img, &(canvas->bpp), \
		&(canvas->line_bytes), &(canvas->endian));
}
