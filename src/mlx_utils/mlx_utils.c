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

	dst = img->img_addr + (y * img->line_bytes + x * (img->bpp/8));
	*(unsigned int*)dst = color;
}