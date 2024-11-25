//CABECERA!!
#include "mini_rt.h"

int	set_ambient(char *line, t_scene *scene)
{
	int			i;
	t_ambient	*amb;

	amb = malloc(sizeof(t_ambient));
	i = skip_space(line);
	amb->ratio = ft_atod_val(&line[i]);
	i += skip_num(&line[i]);
	amb->color = read_color(&line[i]);
	i += skip_vec(&line[i]);
	scene->ambient_light = amb;
	return (check_line_end(&line[i]));
}

int	set_camera(char *line, t_scene *scene)
{
	t_camera	cam;
	int			i;
	t_tuple		to_p;

	i = skip_space(line);
	scene->camera = malloc(sizeof(t_camera));
	scene->camera->position_p = read_point(&line[i]);
	i += skip_vec(&line[i]);
	to_p = read_vec(&line[i]);
	ft_normalized_vec_check(to_p);
	to_p = ft_sub_tuples(scene->camera->position_p, ft_negate_tuple(to_p));
	i += skip_vec(&line[i]);
	cam = ft_build_camera(HEIGHT, WIDTH, ft_atod_val(&line[i]));
	i += skip_num(&line[i]);
	cam.transformations_matrix = ft_matrix_view_transform(\
		scene->camera->position_p, to_p, ft_build_tuple(0, 1, 0, VECTOR));
	*(scene->camera) = cam;
	return (check_line_end(&line[i]));
}

int	set_light(char *line, t_scene *scene)
{
	t_point_light	*light;
	int				i;

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

int	set_sphere(char *line, t_scene *scene)
{
	t_sphere	*sphere;
	int			i;
	int			color;

	i = skip_space(line);
	sphere = malloc(sizeof(t_sphere));
	sphere->origin = read_point(&line[i]);
	i += skip_vec(&line[i]);
	sphere->radius = ft_atod_val(&line[i]) / 2;
	i += skip_num(&line[i]);
	color = read_color(&line[i]);
	i += skip_vec(&line[i]);
	ft_add_obj(scene, SPHERE, sphere, color);
	return (check_line_end(&line[i]));
}

int	set_cylinder(char *line, t_scene *scene)
{
	t_cylinder	*cylinder;
	int			i;
	int			color;

	i = skip_space(line);
	cylinder = malloc(sizeof(t_cylinder));
	cylinder->origin = read_vec(&line[i]);
	i += skip_vec(&line[i]);
	cylinder->nrm_vector = read_vec(&line[i]);
	i += skip_vec(&line[i]);
	cylinder->diameter = ft_atod_val(&line[i]);
	i += skip_num(&line[i]);
	cylinder->height = ft_atod_val(&line[i]);
	i += skip_num(&line[i]);
	color = read_color(&line[i]);
	i += skip_vec(&line[i]);
	ft_add_obj(scene, CYLINDER, cylinder, color);
	return (check_line_end(&line[i]));
}

int	set_plane(char *line, t_scene *scene)
{
	t_plane		*plane;
	int			i;
	int			color;

	i = skip_space(line);
	plane = malloc(sizeof(t_plane));
	plane->origin = read_vec(&line[i]);
	i += skip_vec(&line[i]);
	plane->nrm_vector = read_vec(&line[i]);
	i += skip_vec(&line[i]);
	color = read_color(&line[i]);
	i += skip_vec(&line[i]);
	ft_add_obj(scene, PLANE, plane, color);
	return (check_line_end(&line[i]));
}
