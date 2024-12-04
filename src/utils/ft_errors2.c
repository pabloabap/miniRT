/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:29:25 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:29:28 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/** Comprueba si se está recibiendo un punto en la operación a realizar */
void	ft_sp_normal_at_check(double w)
{
	if (VECTOR == w)
	{
		ft_putstr_fd("Error\nVector recibido, se necesita punto ", 2);
		ft_putstr_fd("de la superfice de la esfera para obtener ", 2);
		ft_putendl_fd("su vector de normalización.", 2);
		exit (TUPLE_OPS_ERROR);
	}
}

/** Retorna mensaje de error si alguna llamada a la librería mlx falla */
void	ft_mlx_failure_check(void *p)
{
	if (NULL == p)
	{
		ft_putstr_fd("Error\nFallo en la API de mlx al peparar ", 2);
		ft_putendl_fd("la ventana y las imagenes.", 2);
		exit (MLX_ERROR);
	}
}

/**
 * Comprueba el tipo de los parametros pasados a la funcion 
 * `ft_matrix_view_transform` y muestra error en caso de que:
 * `from_p` o `to_p` no sean POINTS o `up_v` no sea VECTOR.
 */
void	ft_matrix_view_transform_check(t_tuple from_p, t_tuple to_p, \
	t_tuple up_v)
{
	if (POINT != from_p.w)
	{
		ft_putstr_fd("Error\nfrom_p argument of ft_matrix_view_transform", 2);
		ft_putstr_fd(" function must be a POINT", 2);
		exit (MATRIX_VIEW_ERROR);
	}
	if (POINT != to_p.w)
	{
		ft_putstr_fd("Error\nto_p argument of ft_matrix_view_transform", 2);
		ft_putstr_fd(" function must be a POINT", 2);
		exit (MATRIX_VIEW_ERROR);
	}
	if (VECTOR != up_v.w)
	{
		ft_putstr_fd("Error\nup_v argument of ft_matrix_view_transform", 2);
		ft_putstr_fd(" function must be a VECTOR", 2);
		exit (MATRIX_VIEW_ERROR);
	}
}

/** Retorna mensaje de error el vector `v_v` no está normalizado*/
void	ft_normalized_vec_check(t_tuple v_v)
{
	if (ft_magnitude(v_v) < 0.9 || ft_magnitude(v_v) > 1.1)
	{
		ft_putstr_fd("Error\nVector normal, no normalizado. ", 2);
		ft_putendl_fd("Magnitud distinta a 1.", 2);
		exit (NORMALIZATION_ERROR);
	}
}

/** Retorna mensaje de error si falla malloc.*/
void	ft_malloc_check(void *p)
{
	if (NULL == p)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putendl_fd(strerror(errno), 2);
		exit (errno);
	}
}
