//CABECERA

#include "mini_rt.h"

static void	ft_set_sp_transformations_matrix(t_oitem *obj, t_sphere *sp);
static void	ft_set_pl_transformations_matrix(t_oitem *obj, t_plane *pl);

/**
 * Establece la matriz de transformación inicial del objeto
 * creado, es decir, la traslación de su origen.
 * @param objs_item Puntero al elemento objeto a transformar.
 * @param o_type Tipo de elemento a transformar.
 * @return Nada, actualiza el atributo `transformations_matrix` del
 * 		objeto.
 */
void	ft_set_transformations_matrix(t_oitem *obj_item, int o_type)
{
	if (SPHERE == o_type)
	{
		ft_set_sp_transformations_matrix(obj_item, \
			((t_sphere *)obj_item->obj_struct));
	}
	else if (PLANE == o_type)
		ft_set_pl_transformations_matrix(obj_item, \
			((t_plane *)obj_item->obj_struct));
	else if (CYLINDER == o_type)
	{
		ft_set_cy_transformations_matrix(obj_item, \
			((t_cylinder *)obj_item->obj_struct));
	}
}

/**
 * Construye la matriz de rotación a aplicar a un plano.
 * @param obj Objeto al que aplicar las transformaciones.
 * @param sp `t_sphere` struct que contiene `obj`.
 * @return Nada. Actualiza mediante punteros el atributo 
 * 		`transformations_matrix` del objeto y el origen de la esfera
 * 		a su origen en las coordenadas del objeto.
 */
static void	ft_set_sp_transformations_matrix(t_oitem *obj, t_sphere *sp)
{
	obj->transformations_matrix = ft_matrix_translation(\
		ft_identity_matrix(4, 4), sp->origin.x, sp->origin.y, sp->origin.z);
	sp->origin = ft_build_tuple(0, 0, 0, POINT);
}

/**
 * Construye la matriz de rotación a aplicar a un plano.
 * @param obj Objeto al que aplicar las transformaciones.
 * @param pl `t_plane`struct que contiene `obj`.
 * @return Nada. Actualiza mediante punteros el atributo 
 * 		`transformations_matrix` del objeto y el origen del plano
 * 		a su origen en las coordenadas del objeto.
 */
static void	ft_set_pl_transformations_matrix(t_oitem *obj, t_plane *pl)
{
	double	x_deg;
	double	y_deg;

	x_deg = acos(ft_dot(pl->nrm_vector, ft_build_tuple(0, -1, 0, VECTOR))) \
		* (180 / M_PI);
	y_deg = acos(ft_dot(pl->nrm_vector, ft_build_tuple(0, 0, 1, VECTOR))) \
		* (180 / M_PI);
	ft_normalized_vec_check(pl->nrm_vector);
	obj->transformations_matrix = ft_matrix_translation(\
		ft_matrix_rotation(ft_matrix_rotation(\
			ft_identity_matrix(4, 4), X, x_deg), Y, y_deg), \
		pl->origin.x, pl->origin.y, pl->origin.z);
	pl->origin = ft_build_tuple(0, 0, 0, POINT);
}


void ft_set_cy_transformations_matrix(t_oitem *obj, t_cylinder *cy)
{
    double x_deg;
    double y_deg;
    double z_deg;

    // Calcular los ángulos de rotación en los ejes X, Y y Z
	x_deg = acos(ft_dot(cy->nrm_vector, ft_build_tuple(1, 0, 0, VECTOR))) * (180 / M_PI);  // Rotación en X
	y_deg = acos(ft_dot(cy->nrm_vector, ft_build_tuple(0, 1, 0, VECTOR))) * (180 / M_PI);  // Rotación en Y
	z_deg = acos(ft_dot(cy->nrm_vector, ft_build_tuple(0, 0, 1, VECTOR))) * (180 / M_PI);  // Rotación en Z

	// Print the calculated angles
	printf("x_deg: %f, y_deg: %f, z_deg: %f\n", x_deg, y_deg, z_deg);

    ft_normalized_vec_check(cy->nrm_vector); // Asegurarse de que el vector normal esté normalizado

    // Calcular la matriz de transformaciones: traslación y rotaciones
    obj->transformations_matrix = ft_matrix_translation(
        ft_matrix_rotation(ft_matrix_rotation(ft_matrix_rotation(
            ft_identity_matrix(4, 4), X, x_deg), Y, y_deg), Z, z_deg),
        cy->origin.x, cy->origin.y, cy->origin.z);

    // Ajustar el origen del cilindro para que esté en el centro
    cy->origin = ft_build_tuple(0, 0, 0, POINT);
}

/*  CODIGO ANTIGUO QUE NO FUNCIONABA POR SI EL ANTERIOR DEJA DE FUNCIONAR COMO
 * SE ESPERA TENER EN CUENTA LA TRANSFORMACION QUE HAGA FALTA EN EL EJE z.
static void	ft_set_pl_transformations_matrix(t_oitem *obj, t_plane *pl)
{
	double	x_deg;
	double	y_deg;
	double	z_deg;

	x_deg = acos(ft_dot(pl->nrm_vector, ft_build_tuple(0, 1, 0, VECTOR))) \
		* (180 / M_PI);
	y_deg = acos(ft_dot(pl->nrm_vector, ft_build_tuple(0, 0, 1, VECTOR))) \
		* (180 / M_PI);
	z_deg = acos(ft_dot(pl->nrm_vector, ft_build_tuple(1, 1, 0, VECTOR))) \
		* (180 / M_PI);
	ft_normalized_vec_check(pl->nrm_vector);
	obj->transformations_matrix = ft_matrix_translation(\
		ft_matrix_rotation(ft_matrix_rotation(ft_matrix_rotation(\
			ft_identity_matrix(4, 4), X, x_deg), Y, y_deg), Z, z_deg), \
		pl->origin.x, pl->origin.y, pl->origin.z);
	pl->origin = ft_build_tuple(0, 0, 0, POINT);
} */