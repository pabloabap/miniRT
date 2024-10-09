// CABECERA

#include "../include/mini_rt.h"

// MAIN TRASPOSICION MATRICES
int main(void)
{
	t_matrix m1;

	m1 = ft_build_matrix(4, 4);
	m1.val[0][0] = 1; 
	m1.val[0][1] = 2;
	m1.val[0][2] = 3;
	m1.val[0][3] = 4;
	m1.val[1][0] = 5;
	m1.val[1][1] = 6;
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

	int i = 0, j = 0;
	while (i < m1.rows)
	{
		while (j < m1.cols)
		{
			printf("| %d ", m1.val[i][j]);
			j ++;
		}
		printf ("|\n");
		j = 0;
		i ++;
	}

	ft_matrix_transpos(&m1);
	i = 0;
	j = 0;
	while (i < m1.rows)
	{
		while (j < m1.cols)
		{
			printf("| %d ", m1.val[i][j]);
			j ++;
		}
		printf ("|\n");
		j = 0;
		i ++;
	}
}


/*
___ MAIN COLOREAR VENTANA___
int main(void)
{
	void		*mlx;
	t_canvas	canvas;
	void		*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "miniRT");
	canvas.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	canvas.img_addr = mlx_get_data_addr(canvas.img, &(canvas.bpp), &(canvas.line_bytes), &(canvas.endian));

	int x = 0, y = 0, color = 0;
	while (y < HEIGHT)
	{
		while(x < WIDTH)
		{
			color = ft_create_trgb(0, (x / 2) % 255, (x * y / 2) % 255, (x * x / 2) % 255);
			ft_mlx_pixel_put(&canvas, x, y, color);
			x ++;
		}
		x = 0;
		printf ("LINEA: %d COMPLETADA, COLOR %X\n", y, color);
		y ++;
	}
	mlx_put_image_to_window(mlx, mlx_win, canvas.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

___ MAIN MULTIPLICACION MATRICES ___
/*
int main(void)
{
	t_matrix m1;
	t_matrix m2;
	t_matrix m3;
	m1 = ft_build_matrix(4, 4);
	m2 = ft_build_matrix(4, 4);
	m3 = ft_build_matrix(4, 4);
	m1.val[0][0] = 1; 
	m1.val[0][1] = 2;
	m1.val[0][2] = 3;
	m1.val[0][3] = 4;
	m1.val[1][0] = 5;
	m1.val[1][1] = 6;
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
	m2.val[0][0] = 1; 
	m2.val[0][1] = 2;
	m2.val[0][2] = 3;
	m2.val[0][3] = 4;
	m2.val[1][0] = 5;
	m2.val[1][1] = 6;
	m2.val[1][2] = 7;
	m2.val[1][3] = 8;
	m2.val[2][0] = 9; 
	m2.val[2][1] = 10;
	m2.val[2][2] = 11;
	m2.val[2][3] = 12;
	m2.val[3][0] = 13;
	m2.val[3][1] = 14;
	m2.val[3][2] = 15;
	m2.val[3][3] = 16;
	
	m3 = ft_matrix_mult(m1, m2);
	int i = 0, j = 0;
	while (i < m3.rows)
	{
		while (j < m3.cols)
		{
			printf("| %d ", m3.val[i][j]);
			j ++;
		}
		printf ("|\n");
		j = 0;
		i ++;
	}
}
*/