// CABECERA

#include "../include/mini_rt.h"

int main(int argc, char **argv)
{
	t_matrix	m1;

	if (argc == 4)
	{
		m1 = ft_build_matrix(ft_atoi(argv[1]),ft_atoi(argv[2]));
		ft_fill_matrix(&m1, argv[3]);
		printf ("%d\n",ft_matrix_det(m1, 0, 0));		
	}

	return (0);
}
/*
// CABECERA

#include "../include/mini_rt.h"

// MAIN TRASPOSICION MATRICES
int main(void)
{
	t_matrix	m1;

	m1 = ft_build_matrix(4,4);

	ft_fill_matrix(&m1, "1,2,3,4;5,6,7,8;9,10,11,12;13,14,15,16;");
	ft_print_matrix(m1);
	//printf ("%d\n",ft_matrix_det(m1, 0, 0));
	return (0);
}

*/
