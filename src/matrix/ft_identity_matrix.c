//CABECERA
#include "../../include/mini_rt.h"

/**
 * Devuelve una matriz identidad con las `rows` y `cols` indicadas.
 */
t_matrix	ft_identity_matrix(int rows, int cols)
{
	int				i;
	int				j;
	t_matrix		matrix;

	i = 0;
	j = 0;
	matrix.rows = rows;
	matrix.cols = cols;
	matrix.det = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (i == j)
				matrix.val[i][j++] = 1;
			else
				matrix.val[i][j++] = 0;
		}
		j = 0;
		i ++;
	}
	return (matrix);
}
