// CABECERA !!!

#ifndef MINI_RT
# define MINI_RT

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

typedef enum e_coor
{
	X,
	Y,
	Z,
	W
}	t_coor;

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


typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;


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

typedef struct s_ray
{
	t_vec3	direction;
	t_point	origin;
}	t_ray;

typedef struct s_proyectil
{
	int	pos[2];
	int	vel[2];
}	t_proyectil;

typedef struct s_env
{
	int	grav[2];
	int	wind[2];
}	t_env;

// ___MLX___
void	ft_mlx_pixel_put(t_canvas *img, int x, int y, int color);
int		ft_create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);


#endif
