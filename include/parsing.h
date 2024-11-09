
#ifndef PARSING_H
#define PARSING_H

# include "./mini_rt.h"

int is_space(char c);
double	add_decimal(float n, char *line);
double	ft_atod(char *line);
t_tuple read_point(char *line);
t_tuple read_vec(char *line);
int		skip_num(char *line);
int		skip_vec(char *line);


int read_scene(char *path, t_scene *scene);
void    print_scene(t_scene *scene);

int set_ambient(char *line, t_scene *scene);
int set_camera(char *line, t_scene *scene);
int set_light(char *line, t_scene *scene);


int read_color(char *line);
int set_rgb(int r, int g, int b);
int get_red(int c);
int get_green(int c);
int get_blue(int c);
#endif

