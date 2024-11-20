#include "mini_rt.h"

int set_ambient(char *line, t_scene *scene)
{
    int         i;
    t_ambient   *amb;

    amb = malloc(sizeof(t_ambient));
    i = skip_space(line);
    amb->ratio = ft_atod_val(&line[i]);
    i += skip_num(&line[i]);
    amb->color = read_color(&line[i]);
    i += skip_vec(&line[i]);
    scene->ambient_light = amb;
    return (check_line_end(&line[i]));
}

int set_camera(char *line, t_scene *scene)
{
    t_camera    cam;
    int         i;
    t_tuple     origin_p;
    t_tuple     to_p;
    double      fov_deg;
    
    i = skip_space(line);
    scene->camera = malloc(sizeof(t_camera));
    origin_p = read_point(&line[i]);
    i += skip_vec(&line[i]);
    to_p = ft_sub_tuples(origin_p, ft_negate_tuple(read_vec(&line[i])));
    i += skip_vec(&line[i]);
    fov_deg = ft_atod_val(&line[i]);
    i += skip_num(&line[i]);
    cam = ft_build_camera(HEIGHT, WIDTH, fov_deg);
    cam.transformations_matrix = ft_matrix_view_transform(origin_p, to_p, ft_build_tuple(0, 1, 0, VECTOR));
    *(scene->camera) = cam;
    return (check_line_end(&line[i]));
}

int set_light(char *line, t_scene *scene)
{
    t_point_light   *light;
    int     i;

    light = malloc(sizeof(t_point_light));
    i = skip_space(line);
    light->position = read_point(&line[i]);
    i += skip_vec(&line[i]);
    light->brightness = ft_atod(&line[i]);
    i += skip_num(&line[i]);
    light->color = read_color(&line[i]);
    i += skip_vec(&line[i]);
    scene->light = light;
    return (check_line_end(&line[i]));
}

int set_sphere(char *line, t_scene *scene)
{
    t_sphere    *sphere;
    int         i;
    int         color;
    t_tuple     sp_world_origin;

    i = skip_space(line);
    sphere = malloc(sizeof(t_sphere));
    sphere->origin = ft_build_tuple(0, 0, 0,POINT);
    sp_world_origin = read_point(&line[i]);
    i += skip_vec(&line[i]);
    sphere->radius = ft_atod_val(&line[i]);
    i += skip_num(&line[i]);
    color = read_color(&line[i]);
    i += skip_vec(&line[i]);
    sphere->transformations_matrix = ft_matrix_translation(ft_identity_matrix(4, 4),
        sp_world_origin.x, sp_world_origin.y, sp_world_origin.z);
    ft_add_obj(&scene->objs_list, SPHERE, sphere, color);
    return (check_line_end(&line[i]));
}

int set_cylinder(char *line, t_scene *scene)
{
    t_cylinder  *cylinder;
    int         i;
    int         color;
    t_tuple     cy_world_origin;

    i = skip_space(line);
    cylinder = malloc(sizeof(t_cylinder));
    cylinder->origin = ft_build_tuple(0, 0, 0,POINT);
    cy_world_origin = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    cylinder->nrm_vector = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    cylinder->diameter = ft_atod_val(&line[i]);
    i += skip_num(&line[i]);
    cylinder->height = ft_atod_val(&line[i]);
    i += skip_num(&line[i]);
    color = read_color(&line[i]);
    i += skip_vec(&line[i]);
    cylinder->transformations_matrix = ft_matrix_translation(ft_identity_matrix(4, 4),
        cy_world_origin.x, cy_world_origin.y, cy_world_origin.z);
    ft_add_obj(&scene->objs_list, CYLINDER, cylinder, color);
    return (check_line_end(&line[i]));
}

int set_plane(char *line, t_scene *scene)
{
    t_plane    *plane;
    int         i;
    int         color;
    t_tuple     pl_world_origin;

    i = skip_space(line);
    plane = malloc(sizeof(t_plane));
    plane->origin = ft_build_tuple(0, 0, 0,POINT);
    pl_world_origin = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    plane->nrm_vector = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    color = read_color(&line[i]);
    i += skip_vec(&line[i]);
    plane->transformations_matrix = ft_matrix_translation(ft_identity_matrix(4, 4),
        pl_world_origin.x, pl_world_origin.y, pl_world_origin.z);
    ft_add_obj(&scene->objs_list, PLANE, plane, color);
    return (check_line_end(&line[i]));
}
