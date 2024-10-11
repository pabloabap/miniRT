//CABERECA
#include "../../include/mini_rt.h"

static int	ft_process_matrix(t_matrix m, int r, int *c);
static int	ft_cofactor(int row, int col);
 /*
  * Calcula el determinante de la matriz m.
 */
int	ft_matrix_det(t_matrix m, int r, int c)
{
	int i;

	i = 0;
	ft_matrix_det_check(m);
	if (m.rows > 3)
		m.det += ft_process_matrix(m, r, &c);
	else if (m.rows == 3)
		m.det += ft_process_matrix(m, r, &i);
	else if (2 == m.rows)
		return (m.val[0][0] * m.val[1][1] - m.val[0][1] * m.val[1][0]);
	return (m.det);
}

static int	ft_process_matrix(t_matrix m, int r, int *c)
{
	while (*c < m.cols)
	{
		m.det += m.val[r][*c]  * ft_cofactor(r, *c) \
			* ft_matrix_det(ft_submatrix(m, r, *c), r, *c);
		*c += 1;
	}
	return (m.det);
}

t_matrix	ft_submatrix(t_matrix m, int row, int col)
{
	int			i;
	int			j;
	t_matrix	subm;
	
	i = 0;
	j = 0;
	subm = ft_build_matrix(m.rows -1, m.cols-1);
	while (i < subm.rows)
	{
		while (j < subm.cols)
		{
			subm.val[i][j] = m.val[i + (i >= row)][j + (j >= col)];
			j ++;
		}
		j = 0;
		i ++;
	}
	return (subm);
}

static int	ft_cofactor(int row, int col)
{
	if (0 == ((row + col) % 2))
		return (1);
	else
		return (-1);
}