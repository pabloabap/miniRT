#include "../include/mini_rt.h"

void	ft_print_matrix(t_matrix m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < m.rows)
	{
		while (j < m.cols)
		{
			printf("%02d,", m.val[i][j]);
			j ++;
		}
		printf ("\n");
		i ++;
		j = 0;
	}
}