// CABECERA

#include "../include/mini_rt.h"

// MAIN TRASPOSICION MATRICES
int main(void)
{
	t_matrix m1;

	m1 = ft_build_matrix(4, 4);
	m1.val[0][0] = 1; 
	m1.val[0][1] = 5;
	m1.val[0][2] = -3;
	m1.val[0][3] = 2;
	m1.val[1][0] = -3;
	m1.val[1][1] = 2;
	m1.val[1][2] = 7;
	m1.val[1][3] = 8;
	m1.val[2][0] = 9; 
	m1.val[2][1] = 10;
	m1.val[2][2] = 11;
	m1.val[2][3] = 12;
	m1.val[3][0] = 13;
	m1.val[3][1] = 14;
	m1.val[3][2] = 15;
	m1.val[3][3] = 16;

	printf("___ORIGINAL___\n");
	ft_print_matrix(m1);
	printf("___0,0___\n");
	ft_print_matrix(ft_submatrix(m1, 0, 0));
	printf("___0,1___\n");
	ft_print_matrix(ft_submatrix(m1, 0, 1));
	printf("___0,2___\n");
	ft_print_matrix(ft_submatrix(m1, 0, 2));
	printf("___0,3___\n");
	ft_print_matrix(ft_submatrix(m1, 0, 3));
	printf("___1,0___\n");
	ft_print_matrix(ft_submatrix(m1, 1, 0));
	printf("___1,1___\n");
	ft_print_matrix(ft_submatrix(m1, 1, 1));
	printf("___1,2___\n");
	ft_print_matrix(ft_submatrix(m1, 1, 2));
	printf("___1,3___\n");
	ft_print_matrix(ft_submatrix(m1, 1, 3));
	printf("___2,0___\n");
	ft_print_matrix(ft_submatrix(m1, 2, 0));
	printf("___2,1___\n");
	ft_print_matrix(ft_submatrix(m1, 2, 1));
	printf("___2,2___\n");
	ft_print_matrix(ft_submatrix(m1, 2, 2));
	printf("___2,3___\n");
	ft_print_matrix(ft_submatrix(m1, 2, 3));
	printf("___3,0___\n");
	ft_print_matrix(ft_submatrix(m1, 3, 0));
	printf("___3,1___\n");
	ft_print_matrix(ft_submatrix(m1, 3, 1));
	printf("___3,2___\n");
	ft_print_matrix(ft_submatrix(m1, 3, 2));
	printf("___3,3___\n");
	ft_print_matrix(ft_submatrix(m1, 3, 3));
}
