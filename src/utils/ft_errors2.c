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
