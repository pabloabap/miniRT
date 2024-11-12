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

int set_sphere(char *line, t_scene *scene)
{
    t_sphere    *sphere;
    int         i;
    int         color;

    i = 0;
    sphere = malloc(sizeof(t_sphere));
    while (is_space(line[i]))
        i++;
    sphere->origin = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    sphere->radius = ft_atod(&line[i]);
    i += skip_num(&line[i]);
    color = read_color(&line[i]);
    sphere->transformations_matrix = ft_matrix_translation(ft_identity_matrix(4, 4),
        sphere->origin.x, sphere->origin.x, sphere->origin.x);

    ft_add_obj(&scene->objs_list, SPHERE, sphere, color);
    return (EXIT_SUCCESS);
}

int set_cylinder(char *line, t_scene *scene)
{
    t_cylinder  *cylinder;
    int         i;
    int         color;

    i = 0;
    cylinder = malloc(sizeof(t_cylinder));
    while (is_space(line[i]))
        i++;
    cylinder->origin = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    cylinder->nrm_vector = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    cylinder->diameter = ft_atod(&line[i]);
    i += skip_num(&line[i]);
    cylinder->height = ft_atod(&line[i]);
    i += skip_num(&line[i]);
    color = read_color(&line[i]);
    cylinder->transformations_matrix = ft_matrix_translation(ft_identity_matrix(4, 4),
        cylinder->origin.x, cylinder->origin.x, cylinder->origin.x);
    ft_add_obj(&scene->objs_list, CYLINDER, cylinder, color);
    return (EXIT_SUCCESS);
}

int set_plane(char *line, t_scene *scene)
{
    t_plane    *plane;
    int         i;
    int         color;

    i = 0;
    plane = malloc(sizeof(t_plane));
    while (is_space(line[i]))
        i++;
    plane->origin = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    plane->nrm_vector = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    color = read_color(&line[i]);
    plane->transformations_matrix = ft_matrix_translation(ft_identity_matrix(4, 4),
        plane->origin.x, plane->origin.x, plane->origin.x);
    ft_add_obj(&scene->objs_list, PLANE, plane, color);
    return (EXIT_SUCCESS);
}