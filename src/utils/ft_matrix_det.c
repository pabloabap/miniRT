//CABERECA
#include "../../include/mini_rt.h"

static double	ft_process_matrix(t_matrix m, int r, int *c);
 /**
  * Calcula el determinante de la matriz `m` por adjuntos. 
  * `r`y `c` se utilizan para descartar filas y columnas
  * correspondientes en cada operación recursiva.
  * @return Determinante de la matriz.
 */
double	ft_matrix_det(t_matrix m, int r, int c)
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

static double	ft_process_matrix(t_matrix m, int r, int *c)
{
	while (*c < m.cols)
	{
		m.det += m.val[r][*c]  * ft_cofactor(r, *c) \
			* ft_matrix_det(ft_submatrix(m, r, *c), r, *c);
		*c += 1;
	}
	return (m.det);
}
