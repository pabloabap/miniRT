#include "mini_rt.h"

void    parsing_error(int code)
{
    ft_putstr_fd("Error\n", 2);
    if (code == EXTRA_OBJ)
        ft_putstr_fd("A C y L no se pueden repetir\n", 2);
    if (code == EXTRA_PARAM)
        ft_putstr_fd("Extra parameter detected\n", 2);
    if (code == POINT_FORMAT)
        ft_putstr_fd("Formato de punto incorrecto\n", 2);
    if (code == VEC_FORMAT)
        ft_putstr_fd("Formato de vector incorrecto\n", 2);
    if (code == COLOR_FORMAT)
        ft_putstr_fd("Formato de color incorrecto\n", 2);
    if (code == FALSE_OBJECT)
        ft_putstr_fd("Objeto no reconocido\n", 2);
    if (code == FD_ERROR)
        ft_putstr_fd("File descriptor invalido\n", 2);
    exit (code);
}