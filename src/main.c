/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:15:35 by pabad-ap          #+#    #+#             */
/*   Updated: 2024/11/06 10:15:43 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

t_scene	*scene_init(void)
{
	t_scene	*s;

	s = malloc(sizeof(t_scene));
	if (!s)
		return (NULL);
	s->ambient_light = NULL;
	s->camera = NULL;
	s->light = NULL;
	s->canvas = NULL;
	s->objs_list = NULL;
	return (s);
}

void	free_obj_lst(t_oitem *o_lst)
{
	t_oitem	*tmp;

	tmp = o_lst;
	if (!o_lst)
		return ;
	while (tmp)
	{
		o_lst = o_lst->next;
		free(tmp->obj_struct);
		free(tmp);
		tmp = o_lst;
	}
	return ;
}

void	free_scene(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->ambient_light)
		free(scene->ambient_light);
	if (scene->light)
		free(scene->light);
	if (scene->camera)
		free(scene->camera);
	if (scene->objs_list)
		free_obj_lst(scene->objs_list);
	free(scene);
}

int	check_path(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (i > 3 && path[i - 3] == '.' && path[i - 2] == 'r' && path[i - 1] == 't')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(int ag, char **av)
{
	t_scene	*scene;
	char	*path;

	path = av[1];
	if (ag != 2)
		exit(printf("Error\nOne file argument needed\n"));
	if (check_path(av[1]))
		exit(printf("Error\nInvalid file format\n"));
	scene = scene_init();
	if (!scene)
		return (perror("Scene initialization: "), EXIT_FAILURE);
	if (read_scene(path, scene))
	{
		free_scene(scene);
		return (EXIT_FAILURE);
	}
	ft_prepare_canvas(&scene->canvas, path);
	ft_render_scene(scene);
	mlx_put_image_to_window(scene->canvas->mlx_init, \
		scene->canvas->mlx_win, scene->canvas->img, 0, 0);
	ft_mlx_hook_mng(scene);
	mlx_loop(scene->canvas->mlx_init);
	return (0);
}
