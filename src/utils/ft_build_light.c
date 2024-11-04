//CABECERA
#include "../../include/mini_rt.h"

/** Crea una estructura punto de luz.
 * @param position Punto `t_tuple` con las coordenadas del punto de luz en 
 * 			el espacio.
 * @param brightness Ratio de luminosidad de la luz en rango de 0.0 a 1.0.
 * 
 * @return Estructura punto de luz con las indicaciones especificacadas.
 */
t_point_light	ft_build_light(t_tuple position, double brightness)
{
	t_point_light	light;

	light.position = position;
	if (brightness < 0 || brightness > 1)
	{
		printf("ERROR! - El ratio de luminosidad de una luz tiene que estar");
		printf("en el intervalo 0.0 - 1.0\n");
	}
	light.brightness = brightness;
	return (light);
}
