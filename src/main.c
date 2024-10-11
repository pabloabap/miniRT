// CABECERA

#include "../include/mini_rt.h"

int main(void)
{
	t_matrix	m1;

	m1 = ft_build_matrix(4,4);

	m1.val[0][0] = 45; 
	m1.val[0][1] = 23;
	m1.val[0][2] = 32;
	m1.val[0][3] = 14;
	m1.val[1][0] = 20;
	m1.val[1][1] = 2;
	m1.val[1][2] = 47;
	m1.val[1][3] = 0;
	m1.val[2][0] = 0; 
	m1.val[2][1] = 43;
	m1.val[2][2] = 31;
	m1.val[2][3] = 44;
	m1.val[3][0] = 8;
	m1.val[3][1] = 37;
	m1.val[3][2] = 15;
	m1.val[3][3] = 8;

	printf ("%d\n",ft_matrix_det(m1, 0, 0));
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