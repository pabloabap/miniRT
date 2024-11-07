#include "mini_rt.h"

int set_ambient(char *line, t_scene *scene)
{
    int         i;
    t_ambient   amb;

    i = 0;
    while (is_space(line[i]))
        i++;
    amb.ratio = ft_atod(line);
    i += skip_num(&line[i]);
    amb.color = read_color(&line[i]);
    scene->ambient_light = amb;
    return (EXIT_SUCCESS);
}

int set_light(char *line, t_scene *scene)
{
    t_point_light   light;
    int     i;

    i = 0;
    while (is_space(line[i]))
        i++;
    light.position = read_vec(&line[i]);
    i += skip_vec(&line[i]);
    light.brightness = ft_atod(&line[i]);
    i += skip_num(&line[i]);
    light.color = read_color(&line[i]);
    scene->light = light;
    return (EXIT_SUCCESS);
}