// CABECERA

#include "../include/mini_rt.h"

int main(void)
{
	t_tuple	p;

	p.x = -3;
	p.y = 4;
	p.z = 5;
	p.w = 1;

	printf("(%f, %f, %f, %f)\n", p.x,p.y,p.z,p.w);
	p = ft_inverse_tuple_translation(p, 5, -3, 2);
	printf("(%f, %f, %f, %f)\n", p.x,p.y,p.z,p.w);
	p = ft_tuple_translation(p, 5, -3, 2);
	p = ft_tuple_translation(p, 5, -3, 2);
	printf("(%f, %f, %f, %f)\n", p.x,p.y,p.z,p.w);
	return (0);
}
