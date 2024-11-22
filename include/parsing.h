
#ifndef PARSING_H
#define PARSING_H

# include "./mini_rt.h"

typedef enum e_error
{
    FD_ERROR,
	VAL_ERROR,
    VEC_ERROR,
    COL_ERROR,
    LINE_ERROR
}	t_error;

int is_space(char c);
double	add_decimal(float n, char *line);
double	ft_atod(char *line);
double  ft_atod_val(char *line);
t_tuple read_point(char *line);
t_tuple read_vec(char *line);
int		skip_num(char *line);
int		skip_vec(char *line);


int read_scene(char *path, t_scene *scene);
void    print_scene(t_scene *scene);
void    print_objs(t_oitem *o_lst);

int set_ambient(char *line, t_scene *scene);
int set_camera(char *line, t_scene *scene);
int set_light(char *line, t_scene *scene);
int set_sphere(char *line, t_scene *scene);
int set_cylinder(char *line, t_scene *scene);
int set_plane(char *line, t_scene *scene);

int check_line(char *line, int obj);
int check_line_end(char *line);

int skip_space(char *line);
int skip_num2(char *line);
int is_num(char *line, int end);
int is_val(char *line);
int is_vector(char *line);

int read_color(char *line);
int set_rgb(int r, int g, int b);
int get_red(int c);
int get_green(int c);
int get_blue(int c);

#endif

