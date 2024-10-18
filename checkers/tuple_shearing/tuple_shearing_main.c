#include "../include/mini_rt.h"

int main(void)
{
	t_tuple	p;
	t_tuple	p2;

	p.x = 2;
	p.y = 3;
	p.z = 4;
	p.w = 1;
	p2 = p;
	

	printf("(%f, %f, %f, %f)\n", p.x,p.y,p.z,p.w);
	p = ft_tuple_shearing(p, X, Y, 1);
	printf("(%f, %f, %f, %f)\n", p.x,p.y,p.z,p.w);
	p = p2;
	p = ft_tuple_shearing(p, X, Z, 1);
	printf("(%f, %f, %f, %f)\n", p.x,p.y,p.z,p.w);
	p = p2;
	p = ft_tuple_shearing(p, Y, X, 1);
	printf("(%f, %f, %f, %f)\n", p.x,p.y,p.z,p.w);
	p = p2;
	p = ft_tuple_shearing(p, Y, Z, 1);
	printf("(%f, %f, %f, %f)\n", p.x,p.y,p.z,p.w);
	p = p2;
	p = ft_tuple_shearing(p, Z, X, 1);
	printf("(%f, %f, %f, %f)\n", p.x,p.y,p.z,p.w);
	p = p2;
	p = ft_tuple_shearing(p, Z, Y, 1);
	printf("(%f, %f, %f, %f)\n", p.x,p.y,p.z,p.w);
	p = p2;
	
	return (0);
}