// CABECERA

#include "../include/mini_rt.h"

int main(void)
{
	t_ray		ray;
	t_sphere	sphere;
	double		tan[2];

	ray.origin =  ft_build_tuple(0, 0, 0, POINT);
	ray.direction =  ft_build_tuple(0, 0, 1, VECTOR);
	sphere.id = 0;
	sphere.origin = ft_build_tuple(0, 0, 0, POINT);
	sphere.radius = 1;
	ft_sphere_intersection(ray, sphere, &tan[0]);
	printf ("t1 = %f, t2 = %f\n", tan[0], tan[1]);
	return (0);
}
