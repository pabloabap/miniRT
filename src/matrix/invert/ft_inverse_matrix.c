//CABERECA

#include "../../../include/mini_rt.h"

/* Calculo de la matriz inversa de la matriz `m` recibida como parametro*/
t_matrix ft_inverse_matrix(t_matrix *m)
{
	int			i;
	int			j;
	t_matrix	inverse_matrix;
	t_matrix	tmp;
	t_matrix	adj_matrix;

	i = 0;
	j = 0;
	m->det = ft_matrix_det(*m, 0, 0);
	inverse_matrix = ft_matrix_transpos(*m);
	tmp = inverse_matrix;
	// printf ("___TRASPUESTA___\n");
	// ft_print_matrix(inverse_matrix);
	while (i < inverse_matrix.rows)
	{
		while (j < inverse_matrix.cols)
		{
			adj_matrix = ft_submatrix(tmp, i, j);
			// printf ("___ADJUNTA (%02d, %02d)\n", i, j);
			// ft_print_matrix(adj_matrix);
			inverse_matrix.val[i][j] = ft_matrix_det(adj_matrix, 0, 0) \
				* ft_cofactor(i, j);
			j ++;
		}
		i ++;
		j = 0;
	}
	// printf ("___MATRIZ RESULTANTE___\n");
	// ft_print_matrix(inverse_matrix);
	ft_scalar_mult(&inverse_matrix, 1/m->det, MATRIX);
	// printf ("___MATRIZ * DETERMINANTE___\n");
	// ft_print_matrix(inverse_matrix);
	return (inverse_matrix);
}