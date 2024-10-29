//CABECERA

#include "../../include/mini_rt.h"

/** Pendiente de completar. Son atributos de un objeto
 * para calcular como le afecta la luz.
 */
t_material ft_default_material(int color)
{
	t_material	m;

	m.color = color;
	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	return (m);
}