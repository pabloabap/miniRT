/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_canvas.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:19:05 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/07 15:20:44 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/**
 * Inicializa ventana, imagenes y atributos de las mismas.
 */
void	ft_prepare_canvas(t_canvas **canvas, char *title)
{
	t_canvas	*initialized_canvas;
	char		*file_name;

	initialized_canvas = (t_canvas *)malloc(sizeof(t_canvas));
	file_name = ft_strrchr(title, '/');
	if (file_name)
		title = ++file_name;
	(*canvas) = initialized_canvas;
	(*canvas)->mlx_init = mlx_init();
	ft_mlx_failure_check((*canvas)->mlx_init);
	(*canvas)->mlx_win = mlx_new_window((*canvas)->mlx_init, WIDTH, HEIGHT, \
		title);
	ft_mlx_failure_check((*canvas)->mlx_win);
	(*canvas)->img = mlx_new_image((*canvas)->mlx_init, WIDTH, HEIGHT);
	ft_mlx_failure_check((*canvas)->img);
	(*canvas)->img_addr = mlx_get_data_addr((*canvas)->img, &((*canvas)->bpp), \
		&((*canvas)->line_bytes), &((*canvas)->endian));
}
