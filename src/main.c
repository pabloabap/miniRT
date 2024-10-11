// CABECERA

#include "../include/mini_rt.h"

int main(void)
{
	t_matrix	m1;

	m1 = ft_build_matrix(4,4);

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

	ft_print_matrix(m1);
	printf ("%d\n",ft_matrix_det(m1, 0, 0));
	ft_inverse_matrix(&m1);
	return (ft_matrix_det(m1, 0, 0));
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