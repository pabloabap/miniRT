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

typedef enum e_objects
{
	SPHERE
}	t_objects;

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

typedef struct s_ray
{
	t_tuple	origin;		//Matrix
	t_tuple	direction; //Vector
	//struct s_ray	*next;
}	t_ray;

typedef struct s_sphere
{
	int		id;
	t_tuple	origin; //Centro de la circunferencia (punto)
	double	radius; //Radio de la circunferencia
}	t_sphere;

typedef struct s_intersection
{
	int		inter_count;
	double	inter_points[2];
	int		obj_id;
	struct s_intersection *prev;
	struct s_intersection *next;
}	t_intersection;


// ___MLX___
void		ft_mlx_pixel_put(t_canvas *img, int x, int y, int color);
int			ft_create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);


//___OPERACIONES GENERALES___

t_tuple	ft_build_tuple(double x, double y, double z, int w);
t_tuple	ft_add_tuples(t_tuple a, t_tuple b);
t_tuple	ft_sub_tuples(t_tuple a, t_tuple b);
t_tuple	ft_negate_tuple(t_tuple a);
t_tuple	ft_mult_tuples(t_tuple a, t_tuple b);
void	ft_scalar_mult (void *elem, double s, int elem_type);


//___OPERACIONES CON VECTORES___

double	ft_magnitude(t_tuple v);
void	ft_normalize(t_tuple *v);
double	ft_dot(t_tuple v1, t_tuple v2);
t_tuple	ft_cross(t_tuple v1, t_tuple v2);


//___TRANSFORMACIONES DE PUNTO Y VECTORES___

t_matrix	ft_tuple_to_matrix(t_tuple tuple);
t_tuple		ft_matrix_to_tuple(t_matrix tuple);
t_tuple		ft_tuple_translation(t_tuple p, double x, double y, double z);
t_tuple		ft_inverse_tuple_translation(t_tuple p, double x, double y, \
			double z);
t_tuple		ft_tuple_scalation(t_tuple p, double x, double y, double z);
t_tuple		ft_inverse_tuple_scalation(t_tuple p, double x, double y, \
			double z);
t_tuple		ft_tuple_rotation(t_tuple t, int axis, double rot_deg);
t_tuple		ft_inverse_tuple_rotation(t_tuple t, int axis, double rot_deg);
t_tuple		ft_tuple_shearing(t_tuple t, int axis, int over_axis, double val);
t_tuple		ft_inverse_tuple_shearing(t_tuple t, int axis, int over_axis, double val);


//___OPERACIONES CON MATRICES___

t_matrix	ft_build_matrix (int rows, int cols);
t_matrix	ft_identity_matrix(int rows, int cols);
t_matrix	ft_tuple_to_matrix(t_tuple tuple);
t_matrix	ft_matrix_mult(t_matrix m1, t_matrix m2);
t_matrix	ft_matrix_transpos(t_matrix m);
int			ft_cofactor(int row, int col);
t_matrix	ft_submatrix(t_matrix m, int row, int col);
double		ft_matrix_det(t_matrix m, int r, int c);
t_matrix	ft_inverse_matrix(t_matrix *m);

//___RAYTRACING___

t_tuple	ft_rc_position(t_ray ray, double position);
void	ft_sphere_intersection(t_ray ray, t_sphere sphere, double *tan);


//___GESTION DE ERRORES___

void	ft_vectors_op_check(t_tuple a, t_tuple b);
void	ft_tuples_check(int w);
void	ft_matrix_det_check(t_matrix m);
void	ft_matrix_mult_check(t_matrix m1, t_matrix m2);
void	ft_matrix_to_tuple_check(t_matrix m);
void	ft_intersection_check(double *tan);


// ___DEBUGING___
void	ft_print_matrix(t_matrix m);
void 	ft_fill_matrix(t_matrix *m, char *arr);

#endif