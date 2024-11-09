
#include "mini_rt.h"


int read_obj(char *line)
{
    int i;

    i = 0;
    while (is_space(line[i]))
        i++;
    if (line[i] == 'A' && is_space(line[i + 1]))
        return (AMBIENT);
    if (line[i] == 'C' && is_space(line[i + 1]))
        return (CAMERA);
    if (line[i] == 'L' && is_space(line[i + 1]))
        return (LIGHT);
    if (line[i] == 's' && line[i + 1] == 'p' && is_space(line[i + 2]))
        return (SPHERE);
    if (line[i] == 'p' && line[i + 1] == 'l' && is_space(line[i + 2]))
        return (PLANE);
    if (line[i] == 'c' && line[i + 1] == 'y' && is_space(line[i + 2]))
        return (CYLINDER);
    return (-1);
}

int add_object(char *line, t_scene *scene)
{
    int obj;

    obj = read_obj(line);
    if (obj < 0)
        return (printf("Error (invalid identifier)\n"));
    if (obj == AMBIENT)
        return(set_ambient(&line[1], scene));
   if (obj == CAMERA)
        return(set_camera(&line[1], scene));
    if (obj == LIGHT)
        return (set_light(&line[1], scene));
    /*if (obj == SPHERE) 
        return (set_sphere(&line[2], scene));
    if (obj == PLANE)
        return (set_plane(&line[2], scene));
    if (obj == CYLINDER)
        return (set_cylinder(&line[2], scene));*/
    return (EXIT_SUCCESS);
}

int read_scene(char *path, t_scene *scene)
{
    int     fd;
    char    *line;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return(perror("File opening:"), EXIT_FAILURE);
    line = get_next_line(fd);
    while (line)
    {
        add_object(line, scene);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    print_scene(scene);
    return (EXIT_SUCCESS);
}

void    print_scene(t_scene *scene)
{
    if (scene->ambient_light)
    {
        printf("AMBIENT:\tratio: %f\tcolor:[%d, %d, %d]\n", 
                scene->ambient_light->ratio, 
                get_red(scene->ambient_light->color), 
                get_green(scene->ambient_light->color), 
                get_blue(scene->ambient_light->color));
    }
    if (scene->camera)
    {
        printf("CAMERA:\tposition [%f, %f, %f]\torientation:[%f, %f, %f]\tfov:%d\n",
            scene->camera->position_p.x,
            scene->camera->position_p.y,
            scene->camera->position_p.z,
            scene->camera->orientation_v.x,
            scene->camera->orientation_v.y,
            scene->camera->orientation_v.z,
            scene->camera->fov);
    }
    if (scene->light)
    {
        printf("LIGHT:\tposition [%f, %f, %f]\tratio:%f\tcolor:[%d, %d, %d]\n",
            scene->light->position.x,
            scene->light->position.y,
            scene->light->position.z,
            scene->light->brightness,
            get_red(scene->light->color),
            get_green(scene->light->color),
            get_blue(scene->light->color));
    }

}

