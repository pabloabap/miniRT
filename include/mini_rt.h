// CABECERA !!!

#ifndef MINI_RT_H
# define MINI_RT_H

# define WIDTH 500
# define HEIGHT 500

#include <sys/types.h>	//open
#include <sys/stat.h>	//open
#include <fcntl.h>		//open
#include <unistd.h>		//close, read, write
#include <stdio.h>		//printf, perror
#include <stdlib.h>		//malloc, free, exit
#include <string.h>		//strerror
#include <math.h>		//math
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/libft/libft.h"

typedef enum e_coor
{
	X,
	Y,
	Z,
	W
}	t_coor;

typedef enum e_elemet_type
{
	VECTOR,
	POINT,
	MATRIX
}	t_element_type;

typedef struct s_canvas
{
	void			*mlx_init;
	void			*mlx_win;
	void			*img;
	char			*img_addr;
	int				bpp;
	int				line_bytes;
	int				endian;
	float			scaler_x;
	float			scaler_y;
	unsigned int	color;
	int				min_x;
	int				max_x;
	int				min_y;
	int				max_y;
}					t_canvas;

/*
 * Estructura para puntos y vectores. Los diferenciamos con el atributo w,
 * asignando 0 a los vectors y 1 a los puntos. Esto nos permite comprobar
 * si se puede realizar una operación con ellos o no. Por ejemplo,
 * matemáticamente no tiene sentido sumar dos puntos, por lo que si
 * los sumas w=2 y esto nos alertara de que se está intentando hacer una 
 * operación no permitida. Sin embargo, si sumas un vector a un punto
 * w = 1, lo que significa que se genera otro punto desplazado las unidades
 * especificadas por el vector.
*/
typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	int		w;
}	t_tuple;


typedef struct s_vec3
{
	// double, hasta 14 decimales | float, hasta 6 decimales. Las coordenadas representan la dirección del vector.
	double	coor[3];
	double	norm[3];
	//double unit_vec //Vector de magnitud 1.0
	double	magnitude; // |v| = sqrt(x*x + y*y + z*z) Longitud del vector
	/* ___OPERACIONES___
		- Resta de dos puntos = vector
		- Suma vectores -> Equivalente a poner un vector detras de otro
		- Multiplicar vector por un número = Escalar vector, hacerlo más largo o corto
		- Dot product -> Define si dos vectores apuntan a la misma direccion ( > 0), son 
			perpendiculares (0) u opuestos ( < 0). 
		- Cross product -> Devuelve otro vector perpendicular a ambos, se usa para calcular el vector
			normal de una superficie (Vector perpendicular a la superficie en el punto de interés).
	*/
}	t_vec3;

/**
 * Creamos la estrucutra matrix para hacer operaciones con matrices. Como el máximo
 * rango de las matrices de transformación será 4x4 al trabajar en 3D, reservamos por 
 * defecto este espacio en el stack para evitar gestionar memoría dinámica y leaks de memoria.
 * Al crear la matriz se llenara toda de ceros y con las rows y cols sabremos las dimensiones reales
 * de cada matriz creada.
 */
typedef struct s_matrix
{
	int	rows;
	int cols;
	double	det;
	double val[4][4];
}	t_matrix;

/*typedef struct s_ray
{
	t_vec3	direction;
	t_point	origin;
}	t_ray;
*/

// ___MLX___
void		ft_mlx_pixel_put(t_canvas *img, int x, int y, int color);
int			ft_create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);

//___OPERACIONES GENERALES
// PENDIENTES DE REVISION
void	ft_add_tuples(double *a, double b[4]);
void	ft_sub_tuples(double *a, double b[4]);
void	ft_negate_tuple(double *a);
void	ft_mult_tuples(double *a, double b[4]);
void	ft_scalar_mult (void *elem, double s, int elem_type);

//___OPERACIONES CON MATRICES___
t_matrix	ft_build_matrix (int rows, int cols);
void		ft_matrix_mult(t_matrix *m1, t_matrix m2);
void		ft_matrix_transpos(t_matrix *m1);
int			ft_cofactor(int row, int col);
t_matrix	ft_submatrix(t_matrix m, int row, int col);
int			ft_matrix_det(t_matrix m, int r, int c);
t_matrix	ft_inverse_matrix(t_matrix *m);


//___GESTION DE ERRORES___
void	ft_tuples_check(int w);
void	ft_matrix_det_check(t_matrix m);
void	ft_matrix_mult_check(t_matrix m1, t_matrix m2);

// ___DEBUGING___
void	ft_print_matrix(t_matrix m);
void 	ft_fill_matrix(t_matrix *m, char *arr);

#endif