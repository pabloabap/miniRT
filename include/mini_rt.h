/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:32:23 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:32:27 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# define WIDTH 500
# define HEIGHT 500
# define BUFFER_SIZE 100

# include <sys/types.h>	//open
# include <sys/stat.h>	//open
# include <fcntl.h>		//open
# include <unistd.h>		//close, read, write
# include <stdio.h>		//printf, perror
# include <stdlib.h>		//malloc, free, exit
# include <string.h>		//strerror
# include <math.h>		//math
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/libft.h"

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
	MATRIX,
	SPHERE,
	PLANE,
	CYLINDER,
	LIGHT,
	AMBIENT_LIGHT,
	CAMERA,
	COLOR
}	t_element_type;

typedef enum e_light_types
{
	EFECTIVE_COLOR,
	AMBIENT,
	DIFFUSE,
	SPECULAR
}	t_light_types;

typedef enum e_intersection_vectors
{
	EYE_V,
	LIGHT_V,
	NORMAL_V,
	REFLECTION_V
}	t_inters_v;

typedef struct s_canvas
{
	void			*mlx_init;
	void			*mlx_win;
	void			*img;
	char			*img_addr;
	int				bpp;
	int				line_bytes;
	int				endian;
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
	double	w;
}	t_tuple;

/**
 * Creamos la estrucutra matrix para hacer operaciones con matrices. 
 * Como el máximo rango de las matrices de transformación será 4x4 al trabajar
 * en 3D, reservamos por defecto este espacio en el stack para evitar gestionar
 * memoría dinámica y leaks de memoria.
 * Al crear la matriz se llenará toda de ceros y con las rows y cols sabremos
 * las dimensiones reales de cada matriz creada.
 */
typedef struct s_matrix
{
	int		rows;
	int		cols;
	double	det;
	double	val[4][4];
}	t_matrix;

typedef struct s_ray
{
	t_tuple	origin;		//Punto
	t_tuple	direction; //Vector
	//struct s_ray	*next;
}	t_ray;

typedef struct s_material
{
	double	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

// Lista de todos los objetos de la escena
typedef struct s_oitem
{
	int				obj_id;
	int				obj_type;
	t_material		material;
	void			*obj_struct;
	struct s_oitem	*prev;
	struct s_oitem	*next;

}	t_oitem;

typedef struct s_sphere
{
	t_tuple		origin;		//Centro de la circunferencia (punto)
	double		radius;		//Radio de la circunferencia
	t_matrix	transformations_matrix;
}	t_sphere;

typedef struct s_plane
{
	t_tuple	origin;
	t_tuple	nrm_vector; //Rango [-1, 1]
}	t_plane;

typedef struct s_cylinder
{
	t_tuple	origin;
	t_tuple	nrm_vector;//Rango [-1, 1]
	double	diameter;
	double	height;
}	t_cylinder;

typedef union u_model
{
	t_sphere	sp;
	t_plane		pl;
	t_cylinder	cy;
}	t_omodel;

/**
 * Estructura de intersecciones de un rayo.
 */
typedef struct s_ray_inters
{
	double				inter_point;
	int					obj_id;
	int					hit;
	struct s_ray_inters	*prev;
	struct s_ray_inters	*next;
}	t_ray_inters;

/**
 * Estructura que apunta a las intersecciones de todos los rayos, para poder 
 * liberarlos al final del programa.
 */
typedef struct s_inters
{
	t_ray_inters	*r_i;
	struct s_inters	*next;
}	t_inters;

typedef struct s_point_light
{
	t_tuple	position;
	double	brightness;
}	t_point_light;

typedef struct s_camera
{
	t_tuple	position_p;
	t_tuple	orientation_v; //Rango[-1, 1]
	int		fov; //[0, 180]
}	t_camera;

/** 
 * Estructura que contiene todos los elementos de la escena
 * para poder gestionarlos y liberar memoría de manera centralizada.
 */
typedef struct s_scene
{
	t_point_light	light;
	t_oitem			*objs_list;
	t_inters		*rays_inter_list;
	t_canvas		*canvas;
	int				z_wall; //Pared final donde se reflejaran los objetos
	t_camera		camera;
	/** Pendiente de confirmación
	 * t_ambient_light	ambient_ligh;
	 */
}	t_scene;

// ___MLX___

void			ft_mlx_pixel_put(t_canvas *img, int x, int y, int color);
int				ft_create_trgb(unsigned char t, unsigned char r, \
					unsigned char g, unsigned char b);
unsigned char	ft_get_t(int trgb);
unsigned char	ft_get_r(int trgb);
unsigned char	ft_get_g(int trgb);
unsigned char	ft_get_b(int trgb);

//___OPERACIONES GENERALES___

t_tuple			ft_build_tuple(double x, double y, double z, int w);
t_matrix		ft_build_matrix(int rows, int cols);
t_sphere		ft_build_sphere(t_tuple center, double radius);
t_tuple			ft_add_tuples(t_tuple a, t_tuple b);
t_tuple			ft_sub_tuples(t_tuple a, t_tuple b);
t_tuple			ft_negate_tuple(t_tuple a);
t_tuple			ft_mult_tuples(t_tuple a, t_tuple b);
void			ft_scalar_mult(void *e, double s, int e_type);

//___OPERACIONES CON VECTORES___

double			ft_magnitude(t_tuple v);
t_tuple			ft_normalize(t_tuple v);
double			ft_dot(t_tuple v1, t_tuple v2);
t_tuple			ft_cross(t_tuple v1, t_tuple v2);

//___TRANSFORMACIONES DE PUNTO Y VECTORES___

t_matrix		ft_tuple_to_matrix(t_tuple tuple);
t_tuple			ft_matrix_to_tuple(t_matrix tuple);
t_matrix		ft_matrix_translation(t_matrix m, double x, double y, double z);
t_matrix		ft_matrix_inverse_translation(t_matrix m, double x, double y, \
					double z);
t_matrix		ft_matrix_scalation(t_matrix m, double x, double y, double z);
t_matrix		ft_matrix_inverse_scalation(t_matrix m, double x, double y, \
					double z);
t_matrix		ft_matrix_rotation(t_matrix m, int axis, double rot_deg);
t_matrix		ft_matrix_inverse_rotation(t_matrix m, int axis, \
					double rot_deg);
t_matrix		ft_matrix_shearing(t_matrix m, int axis, int over_axis, \
					double val);
t_matrix		ft_matrix_inverse_shearing(t_matrix m, int axis, int over_axis, \
					double val);

//___OPERACIONES CON MATRICES___

t_matrix		ft_identity_matrix(int rows, int cols);
t_matrix		ft_matrix_mult(t_matrix m1, t_matrix m2);
t_matrix		ft_matrix_transpos(t_matrix m);
int				ft_cofactor(int row, int col);
t_matrix		ft_submatrix(t_matrix m, int row, int col);
double			ft_matrix_det(t_matrix m, int r, int c);
t_matrix		ft_inverse_matrix(t_matrix *m);

//___RAYTRACING___

t_tuple			ft_rc_position(t_ray ray, double position);
void			ft_sphere_inters(t_ray ray, t_oitem sphere, \
					t_ray_inters **i_list);
int				ft_add_inters_sorted(t_ray_inters **i_list, double inter_point, \
					int obj_id);
int				ft_identify_hit(t_ray_inters *i_list);
t_ray_inters	*ft_get_hit(t_ray_inters *i_list);
int				ft_get_hit_color(t_ray_inters *i_list, t_oitem *o_list);
t_oitem			*ft_get_hitted_obj(t_ray_inters *i_list, t_oitem *o_list);

//___LIGHT & SHADING

int				ft_lighting(t_material material, t_point_light light, \
					t_tuple point, t_tuple *inters_vecs);
t_tuple			ft_sp_normal_at(t_sphere sp, t_tuple surface_point);
t_tuple			ft_reflection_vector(t_tuple in, t_tuple normal);

//___GESTION DE ERRORES___

void			ft_vectors_op_check(t_tuple a, t_tuple b);
void			ft_tuples_check(int w);
void			ft_matrix_det_check(t_matrix m);
void			ft_matrix_mult_check(t_matrix m1, t_matrix m2);
void			ft_matrix_to_tuple_check(t_matrix m);
void			ft_sp_normal_at_check(double w);
int				ft_mlx_failure_check(void *p);

//___UTILS___

t_point_light	ft_build_light(t_tuple position, double brightness);
int				ft_obj_id_assignment(void);
int				ft_add_obj(t_oitem **o_list, t_omodel o_to_add, int o_type, \
					int color);
t_material		ft_default_material(int color);
int				ft_add_item_to_inters_list(t_inters **inter_list);
t_inters		*ft_lst_inters_item(t_inters *inter_head);
int				ft_render_scene(t_scene *scene);
int				ft_prepare_scence(t_scene **scene);

//___GNL___

char			*get_next_line(int fd);
size_t			ft_gnl_strlen(const char *s);
char			*ft_gnl_strjoin(char *s1, char *s2);
char			*ft_gnl_strchr(const char *s, int c);
char			*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char			*ft_gnl_strdup(char *s1);

// ___DEBUGING___

void			ft_print_matrix(t_matrix m);
void			ft_print_tuple(t_tuple t);
void			ft_fill_matrix(t_matrix *m, char *arr);
void			ft_print_i_list(t_ray_inters *i_list);

#endif