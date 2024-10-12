// CABECERA

#include "../include/mini_rt.h"

int main(void)
{
	t_tuple	p;
	t_tuple	p2;
	t_tuple	p22;
	t_tuple	p3;
	t_tuple	p33;


	p.x = 0;
	p.y = 1;
	p.z = 0;
	p.w = 1;
	p2.x = 0;
	p2.y = 0;
	p2.z = 1;
	p2.w = 1;
	p22 = p2;
	p3 = p;
	p33 = p;

	printf("(%f, %f, %f, %f)\n", p.x,p.y,p.z,p.w);
	p = ft_tuple_x_rotation(p, 45);
	printf("1.45 - (%f, %f, %f, %f)\n", p.x,p.y,p.z,p.w);
	p = ft_tuple_x_rotation(p3, 90);
	printf("1.90 - (%f, %f, %f, %f)\n", p.x,p.y,p.z,p.w);
	p2 = ft_tuple_y_rotation(p2, 45);
	printf("2.45 - (%f, %f, %f, %f)\n", p2.x,p2.y,p2.z,p2.w);
	p2 = ft_tuple_y_rotation(p22, 90);
	printf("2.90 - (%f, %f, %f, %f)\n", p2.x,p2.y,p2.z,p2.w);
	p3 = ft_tuple_z_rotation(p3, 45);
	printf("45 - (%f, %f, %f, %f)\n", p3.x,p3.y,p3.z,p3.w);
	p3 = ft_tuple_z_rotation(p33, 90);
	printf("90 - (%f, %f, %f, %f)\n", p3.x,p3.y,p3.z,p3.w);
	return (0);
}
