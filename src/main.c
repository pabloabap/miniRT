// CABECERA

#include "../include/mini_rt.h"

int main(void)
{
	t_ray			ray;
	t_sphere		sphere;
	t_sphere		sphere2;
	t_ray_inters	*inters_list;
	t_ray_inters	*tmp;
	

	ray.origin =  ft_build_tuple(0, 0, 0, POINT);
	ray.direction =  ft_build_tuple(0, 0, 1, VECTOR);
	inters_list = NULL;
	sphere = ft_build_sphere(0, 0, 6, 1);
	ft_sphere_inters(ray, sphere, &inters_list);
	sphere = ft_build_sphere(0, 0, 3, 1);
	ft_sphere_inters(ray, sphere, &inters_list);
	sphere = ft_build_sphere(0, 0, 3, 1);
	ft_sphere_inters(ray, sphere, &inters_list);
	tmp = inters_list;
	ft_identify_hit(inters_list);
	printf("__INTERSECTIONS LIST___\n");
	while (tmp)
	{
		printf("INTERS: %f | OBJ_ID: %i | HIT %i | P: %p| PREV: %p | NEXT: %p\n", \
			tmp->inter_point, tmp->obj_id, tmp->hit, tmp, tmp->prev, tmp->next);
		tmp = tmp->next;
	}
	return (0);
}
