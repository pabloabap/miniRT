//CABERECA
#include "../../include/mini_rt.h"

static void ft_mult(t_matrix m1, t_matrix m2, t_matrix *final_matrix);

/** Multiplica las dos matrices recibidas como parametro.
 * En caso de ser incompatibles para multiplicarse retorna
 * mensaje de error y termina el programa.
*/
t_matrix	ft_matrix_mult(t_matrix m1, t_matrix m2)
{
	t_matrix	final_matrix;

	final_matrix = ft_build_matrix(m1.rows, m2.cols);
	if (m1.rows != m2.cols)
	{
		perror("ERROR - El número de filas de la primera matriz tiene");
		perror(" que ser igual al número de columnas de la segunda \n");
		exit (1);
	}
	else
		ft_mult(m1, m2, &final_matrix);
	return (final_matrix);
}

/** Realiza la operación de multiplicación si las matrices sean compatbles 
 * y actualiza el valor de final_matrix.val con el resultado.
*/
static void	ft_mult(t_matrix m1, t_matrix m2, t_matrix *final_matrix)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (i < m1.rows)
	{
		while (j < m1.rows)
		{
			while (k < m1.cols)
			{
				(*final_matrix).val[j][i] += m1.val[j][k] * m2.val[k][i];
				k ++;				
			}
			k= 0;
			j++;
		}
		j = 0;
		i ++;
	}	
}