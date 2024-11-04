//CABECERA

#include "../../include/mini_rt.h"

static t_tuple	ft_normalize_color(int color);

/** 
 * Funcion de alumbrado del modelo de reflexión de Phong
 * @param	material `atributo de las estructuras `t_oitem` con información de 
 * 	color y luminosidad del objeto
 * @param	light Estructura `t_point_light` con información de la ubicación y 
 * 	el ratio de brillo de de un punto de luz.
 * @param	point Punto de impacto del rayo con el objeto.
 * @param	eyev Vector ojo. Vector desde el punto de impacto a la ubicación 
 * 	del punto de vista.
 * @param	normalv Vector normal, perpendicular al punto de impacto en el 
 * 	objeto.
 * @return Retornar el ratio de intensidad a aplicar al color base del punto
 *  de impacto.
 */
double	ft_lighting(t_material material, t_point_light light, t_tuple point, t_tuple eyev, t_tuple normalv)
{
	t_tuple	efective_color;
	t_tuple	lightv;
	t_tuple	ambient;
	t_tuple	diffuse;
	t_tuple	specular;
	double	light_dot_normal;
	t_tuple reflectv;
	double	reflect_dot_eye;

	efective_color = ft_normalize_color(material.color);
	ft_scalar_mult(&efective_color, light.brightness, COLOR);
	lightv = ft_normalize(ft_sub_tuples(light.position, point));
	ambient = efective_color;
	ft_scalar_mult(&ambient,  material.ambient, COLOR);
	light_dot_normal = ft_dot(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = ft_normalize_color(ft_create_trgb(0, 0, 0, 0)); //Black
		specular = ft_normalize_color(ft_create_trgb(0, 0, 0, 0)); //Black
	}
	else
	{
		diffuse = efective_color;
		ft_scalar_mult(&diffuse,  material.diffuse * light_dot_normal, COLOR);
		reflectv = ft_reflection_vector(ft_negate_tuple(lightv), normalv);
		reflect_dot_eye = ft_dot(reflectv, eyev);
		if (reflect_dot_eye <= 0)
			specular = ft_normalize_color(ft_create_trgb(0, 0, 0, 0)); //Black
		else
		{
			light.brightness = light.brightness * material.specular * pow(reflect_dot_eye, material.shininess);
			specular = ft_build_tuple(light.brightness, light.brightness, light.brightness, COLOR);
		}
	}
	ambient = ft_add_tuples(ambient, diffuse);
	ambient.w = COLOR;
	ambient = ft_add_tuples(ambient, specular);
	ambient.w = COLOR;
	return (ambient.x);
}

/**
 * Función que normaliza el color de la escala 0.0 - 255.0 a 0.0 - 1.0
 * para calcular los ratios de luminosidad.
 * @param color Entero con el codigo de color a normalizar.
 * @return `t_tuple` de tipo COLOR con los colores RGB normalizados.
 */
static t_tuple	ft_normalize_color(int color)
{
	return (ft_build_tuple(ft_get_r(color) / 255.0, ft_get_g(color) / 255.0, \
		ft_get_b(color) / 255.0, COLOR));
}