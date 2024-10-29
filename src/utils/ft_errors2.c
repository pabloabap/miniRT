//CABECERA
#include "../../include/mini_rt.h"

void	ft_intersection_check(double *tan)
{
	if (isnan(tan[0]) && isnan(tan[1]))
	{
		ft_putendl_fd("Not ray-sphere intersection.", 2);
		exit (1);
	}
};

void	ft_sp_normal_at_check(double w)
{
	if (VECTOR == w)
	{
		ft_putstr_fd("ERROR - Vector recibido, se necesita punto ", 2);
		ft_putstr_fd("de la superfice de la esfera para obtener ", 2);
		ft_putendl_fd("su vector de normalización.", 2);
		exit (1);
	}
};
