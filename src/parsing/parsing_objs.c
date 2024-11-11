#include "mini_rt.h"

int set_ambient(char *line, t_scene *scene)
{
    int         i;
    t_ambient   *amb;

    amb = malloc(sizeof(t_ambient));
    i = 0;
    while (is_space(line[i]))
        i++;
    amb->ratio = ft_atod(line);
    i += skip_num(&line[i]);
    amb->color = read_color(&line[i]);
    scene->ambient_light = amb;
    return (EXIT_SUCCESS);
}

int set_camera(char *line, t_scene *scene)
{
    t_camera    *cam;
    int         i;

    i = 0;
    cam = malloc(sizeof(t_camera));
    while (is_space(line[i]))
        i++;
    cam->position_p = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    cam->orientation_v = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    cam->fov = ft_atod(&line[i]);
    scene->camera = cam;
    return (EXIT_SUCCESS);
}

int set_light(char *line, t_scene *scene)
{
    t_point_light   *light;
    int     i;

    light = malloc(sizeof(t_point_light));
    i = 0;
    while (is_space(line[i]))
        i++;
    light->position = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    light->brightness = ft_atod(&line[i]);
    i += skip_num(&line[i]);
    light->color = read_color(&line[i]);
    scene->light = light;
    return (EXIT_SUCCESS);
}

/*
typedef struct s_oitem
{
	int				obj_id;
	int				obj_type;
	t_material		material;
	void			*obj_struct;
	struct s_oitem	*prev;
	struct s_oitem	*next;
}	t_oitem;

typedef struct s_scene
{
	t_point_light	*light;
	t_oitem			*objs_list;
	t_inters		*rays_inter_list;
	t_canvas		*canvas;
	int				z_wall; //Pared final donde se reflejaran los objetos
	t_camera		*camera;
	t_ambient		*ambient_light;
}	t_scene;
*/

int set_sphere(char *line, t_scene *scene)
{
    t_sphere    *sphere;
    t_oitem     *obj;
    int         i;
    int         color;

    sphere = malloc(sizeof(t_sphere));
    obj = malloc(sizeof(t_oitem));
    while (is_space(line[i]))
        i++;
    sphere->origin = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    sphere->radius = ft_atod(&line[i]);
    i += skip_num(&line[i]);
    color = read_color(&line[i]);
    //ft_add_obj(&obj,)
    return (EXIT_SUCCESS);
}