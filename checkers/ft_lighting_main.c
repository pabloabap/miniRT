// CABECERA

#include "../include/mini_rt.h"

int main(void)
{
	t_material		m;
	t_tuple			position;
	t_point_light	light;

	m = ft_default_material(1);
	position = ft_build_tuple(0, 0, 0, POINT);
	light.position = ft_build_tuple(0,0,-10,POINT);
	light.brightness = 1;
	printf("===0.1,0.9,1.0=======\n");
	ft_lighting(m, light, position, ft_build_tuple(0,0,-1,VECTOR), ft_build_tuple(0,0,-1,VECTOR));
	printf("====0.1,0.9,0.0=======\n");
	ft_lighting(m, light, position, ft_build_tuple(0,sqrt(2)/2,sqrt(2)/2,VECTOR), ft_build_tuple(0,0,-1,VECTOR));
	printf("===0.1,0.9*sqrt(2)/2,0=======\n");
	light.position = ft_build_tuple(0,10,-10,POINT);
	ft_lighting(m, light, position, ft_build_tuple(0,0,-1,VECTOR), ft_build_tuple(0,0,-1,VECTOR));
	printf("===0.1,0.9*sqrt(2)/2,0.9=======\n");
	ft_lighting(m, light, position, ft_build_tuple(0,-sqrt(2)/2,-sqrt(2)/2,VECTOR), ft_build_tuple(0,0,-1,VECTOR));
	printf("===0.1,0.1,0.1=======\n");
	light.position = ft_build_tuple(0,0,10,POINT);
	ft_lighting(m, light, position, ft_build_tuple(0,0,-1,VECTOR), ft_build_tuple(0,0,-1,VECTOR));
	return (0);
}