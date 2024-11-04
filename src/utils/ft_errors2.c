//CABECERA
#include "../../include/mini_rt.h"

/** Comprueba si se está recibiendo un punto en la operación a realizar */
void	ft_sp_normal_at_check(double w)
{
	if (VECTOR == w)
	{
		ft_putstr_fd("ERROR - Vector recibido, se necesita punto ", 2);
		ft_putstr_fd("de la superfice de la esfera para obtener ", 2);
		ft_putendl_fd("su vector de normalización.", 2);
		exit (1);
	}
}

/** Retorna mensaje de error si alguna llamada a la librería mlx falla */
int	ft_mlx_failure_check(void *p)
{
	if (NULL == p)
	{
		ft_putstr_fd("ERROR - Fallo en la API de mlx al peparar ", 2);
		ft_putendl_fd("la ventana y las imagenes.", 2);
		exit (1);
	}
	else
		return (EXIT_SUCCESS);
}
