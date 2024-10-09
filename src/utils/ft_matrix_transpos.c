//CABERECA
#include "../../include/mini_rt.h"

/** Traspone la matriz recibida como parametro. */
void	ft_matrix_transpos(t_matrix *m1)
{
	int			i;
	int			j;
	t_matrix	tmp_matrix;

	tmp_matrix = ft_build_matrix(m1->cols, m1->rows);
	i = 0;
	j = 0;
	while (i < m1->rows)
	{
		while (j < m1->cols)
		{
			tmp_matrix.val[j][i] = (*m1).val[i][j];
			j++;
		}
		j = 0;
		i ++;
	}
	*m1 = tmp_matrix;
}