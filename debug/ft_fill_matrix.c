#include "../include/mini_rt.h"

void ft_fill_matrix(t_matrix *m, char *arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < m->rows)
	{
		while (j < m->cols)
		{
			(*m).val[i][j] = ft_atoi(arr);
			if ((j + 1) < m->cols)
				arr = ft_strchr(arr, ',') + 1;
			j++;
		}
		arr = ft_strchr(arr, ';') + 1;
		i ++;
		j = 0;
	}
}