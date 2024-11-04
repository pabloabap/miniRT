// CABECERA

#include "../include/mini_rt.h"

int main(int argc, char **argv)
{
	t_matrix	m1;

	if (argc == 4)
	{
		m1 = ft_build_matrix(ft_atoi(argv[1]),ft_atoi(argv[2]));
		ft_fill_matrix(&m1, argv[3]);
		ft_print_matrix(ft_inverse_matrix(&m1));
	}
	return (0);
}
