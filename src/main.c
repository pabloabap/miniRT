// CABECERA

#include "../include/mini_rt.h"

int main(void)
{
	t_matrix	m1;
	t_matrix	m2;

	m1 = ft_build_matrix(4,4);
	m2 = ft_build_matrix(4,2);

	m1.val[0][0] = -5; 
	m1.val[0][1] = 2;
	m1.val[0][2] = 6;
	m1.val[0][3] = -8;
	m1.val[1][0] = 1;
	m1.val[1][1] = -5;
	m1.val[1][2] = 1;
	m1.val[1][3] = 8;
	m1.val[2][0] = 7; 
	m1.val[2][1] = 7;
	m1.val[2][2] = -6;
	m1.val[2][3] = -7;
	m1.val[3][0] = 1;
	m1.val[3][1] = -3;
	m1.val[3][2] = 7;
	m1.val[3][3] = 4;

	m2.val[0][0] = -5; 
	m2.val[0][1] = 2;
	m2.val[1][0] = 6;
	m2.val[1][1] = -8;
	m2.val[2][0] = 1;
	m2.val[2][1] = -5;
	m2.val[3][0] = 1;
	m2.val[3][1] = 8;

	printf("___MATRIX 1: r: %d c: %d___\n", m1.rows, m1.cols);
	ft_print_matrix(m1);
	printf("___MATRIX 2: r: %d c: %d___\n", m2.rows, m2.cols);
	ft_print_matrix(m2);
	printf("___FINAL MATRIX___\n");
	ft_print_matrix(ft_matrix_mult(m1, m2));
	return (0);
}

/*
int main(int argc, char **argv)
{
	t_matrix	m1;

	if (argc == 4)
	{
		m1 = ft_build_matrix(ft_atoi(argv[1]), ft_atoi(argv[2]));
		ft_fill_matrix(&m1, argv[2]);
		ft_print_matrix(m1);
		//printf ("%d\n",ft_matrix_det(m1, 0, 0));
	}
	return (0);
}
*/