//CABECERA

#include "../../include/mini_rt.h"

static double	ft_discriminant(double *v);
static void		ft_fill_v(t_ray ray, t_sphere sphere, double *v);

/**
 * Devuelve los puntos de intersección del rayo `ray` con la esfera `sphere`
 * en el argumento `tan` (tiene que ser un array de dos double).
 */
void	ft_sphere_inters(t_ray ray, t_sphere sphere, t_ray_inters **i_list)
{
	double	v[3];
	double tan[2];

	ft_fill_v(ray, sphere, &v[0]);
	tan[0] = (-v[1] - sqrt(ft_discriminant(&v[0]))) / (2 * v[0]);
	tan[1] = (-v[1] + sqrt(ft_discriminant(&v[0]))) / (2 * v[0]);
	if(!isnan(tan[0]))
		ft_add_inters_sorted(i_list, tan[0], sphere.obj_id);
	if(!isnan(tan[1]))
		ft_add_inters_sorted(i_list, tan[1], sphere.obj_id);
}

/**
 * Define en que punto intersecciona `ray`y `sphere`.
 * @return Discriminante.
 */
static double	ft_discriminant(double *v)
{
	return (v[1] * v[1] - 4 * v[0] * v[2]);
}

/**
 * Rellena `v` con los valores constantes utilizados en las fórmulas
 * para hayar el discriminante y la intersección de rayo con circunferencia.
 * 
 * @param ray Estructura con información del rayo.
 * @param sphere Estructura con información de la esfera.
 * @param v Punteor a array de 3 double que almacenarán los valores constantes
 * 			requeridos en la operaciones de intersección.
 * @return Nada. Actualiza los valores de `v`a través del puntero.
 */
static void	ft_fill_v(t_ray ray, t_sphere sphere, double *v)
{
	t_tuple	v_sphere_to_ray;
	
	v_sphere_to_ray = ft_sub_tuples(ray.origin, sphere.origin);
	v[0] = ft_dot(ray.direction, ray.direction);
	v[1] = 2 * ft_dot(ray.direction, v_sphere_to_ray);
	v[2] = ft_dot(v_sphere_to_ray, v_sphere_to_ray) - 1;
}