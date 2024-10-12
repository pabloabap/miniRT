//CABECERA
#include "../../include/mini_rt.h"

/**
 * Convierte tuplas en matrices para poder hacer operaciones
 * de matries con ellas. Es util para aplicar multiples transorfmaciones
 * a la vez.
 */
t_matrix	ft_tuple_to_matrix(t_tuple tuple)
{
	t_matrix	m;
	
	m = ft_build_matrix(4,1);
	m.val[0][0] = tuple.x;
	m.val[1][0] = tuple.y;
	m.val[2][0] = tuple.z;
	m.val[3][0] = tuple.w;
	return (m);	
}