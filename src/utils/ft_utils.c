//CABECERA
#include "../../include/mini_rt.h"

/**
 * Asigna id disponible al elemento que la invoca;
 * `id`es la variable estática que almacena el id dispoible para la siguiente
 * llamada.
 */
int	ft_obj_id_assignment(void)
{
	int			available_id;
	static int	id = 0;

	available_id = id;
	id ++;
	return (available_id);
}