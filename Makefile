# CABECERA

NAME		= miniRT

DIR_LIBFT	= ./lib/libft
LIBFT_AR	= ./lib/libft/libft.a

#___MLX___
DIR_MLX		= ./lib/minilibx-linux/
MLX_AR		= ./lib/minilibx-linux/libmlx.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -L$(DIR_MLX) -lmlx -lXext -lX11
LIBFT		= -L$(DIR_LIBFT) -lft

INCLUDE		= -Iinclude -I$(DIR_LIBFT) -I$(DIR_MLX)

MAIN		= ./src/main.c

SRCS		=	$(MAIN) \
				./debug/ft_fill_matrix.c \
				./debug/ft_print_matrix.c \
				./debug/ft_print_tuple.c \
				./src/mlx_utils/mlx_utils.c \
				./src/gnl/ft_get_next_line_utils.c \
				./src/gnl/ft_get_next_line.c \
				src/light_shading/ft_lighting.c \
				./src/light_shading/ft_refection_vector.c \
				./src/light_shading/ft_sp_normal_at.c \
				./src/matrix/ft_identity_matrix.c \
				./src/matrix/ft_matrix_mult.c \
				./src/matrix/ft_matrix_transpos.c \
				./src/matrix/invert/ft_cofactor.c \
				./src/matrix/invert/ft_inverse_matrix.c \
				./src/matrix/invert/ft_matrix_det.c \
				./src/matrix/invert/ft_submatrix.c \
				./src/matrix/transformations/ft_matrix_rotation.c \
				./src/matrix/transformations/ft_matrix_scalation.c \
				./src/matrix/transformations/ft_matrix_shearing.c \
				./src/matrix/transformations/ft_matrix_translations.c \
				./src/ray_intersections/ft_add_inters_sorted.c \
				./src/ray_intersections/ft_get_hit.c \
				./src/ray_intersections/ft_get_hit_color.c \
				./src/ray_intersections/ft_identify_hit.c \
				./src/ray_intersections/ft_rc_position.c \
				./src/ray_intersections/ft_sphere_inters.c \
				./src/utils/ft_add_object.c \
				./src/utils/ft_build_light.c \
				./src/utils/ft_build_tuple.c \
				./src/utils/ft_errors.c \
				./src/utils/ft_errors2.c \
				./src/utils/ft_material.c \
				./src/utils/ft_matrix_to_tuple.c \
				./src/utils/ft_build_sphere.c \
				./src/utils/ft_tuple_to_matrix.c \
				./src/utils/general_op.c \
				./src/utils/ft_build_matrix.c \
				./src/utils/ft_utils.c \
				./src/utils/vec_op.c

				
#Object files
DIR_OBJS	= ./build/
OBJS		= $(addprefix $(DIR_OBJS), $(notdir $(patsubst %.c, %.o, $(SRCS))))

HEADERS		= ./include/mini_rt.h

# Directories
DIR_DEBUG = ./debug/
DIR_GNL = ./src/gnl/
DIR_LIGHT_SHADING = ./src/light_shading/
DIR_MLX_UTILS = ./src/mlx_utils/
DIR_MATRIX = ./src/matrix/
DIR_MATRIX_INVERT = ./src/matrix/invert/
DIR_MATRIX_TRANSFORMATIONS = ./src/matrix/transformations/
DIR_RAY_INTERSECTIONS = ./src/ray_intersections/
DIR_UTILS = ./src/utils/

all: libft mlx $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lm $(MLXFLAGS) -o $(NAME)

# Creación de directorio objectos si no existen
$(DIR_OBJS):
	mkdir $(DIR_OBJS)

# ELIMINAR, funciones debugging
$(DIR_OBJS)%.o: $(DIR_DEBUG)%.c $(HEADERS) Makefile | $(DIR_OBJS)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(DIR_OBJS)%.o: $(DIR_MLX_UTILS)%.c $(HEADERS) Makefile | $(DIR_OBJS)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(DIR_OBJS)%.o: $(DIR_UTILS)%.c $(HEADERS) Makefile | $(DIR_OBJS)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(DIR_OBJS)%.o: $(DIR_MATRIX)%.c $(HEADERS) Makefile | $(DIR_OBJS)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(DIR_OBJS)%.o: $(DIR_MATRIX_INVERT)%.c $(HEADERS) Makefile | $(DIR_OBJS)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(DIR_OBJS)%.o: $(DIR_MATRIX_TRANSFORMATIONS)%.c $(HEADERS) Makefile | $(DIR_OBJS)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(DIR_OBJS)%.o: $(DIR_RAY_INTERSECTIONS)%.c $(HEADERS) Makefile | $(DIR_OBJS)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(DIR_OBJS)%.o: $(DIR_LIGHT_SHADING)%.c $(HEADERS) Makefile | $(DIR_OBJS)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(DIR_OBJS)%.o: $(DIR_GNL)%.c $(HEADERS) Makefile | $(DIR_OBJS)

	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(DIR_OBJS)%.o: $(MAIN) $(HEADERS) Makefile | $(DIR_OBJS)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@


libft:
	make -C $(DIR_LIBFT)

mlx:
	make -C $(DIR_MLX)

clean:
	rm -rf $(DIR_OBJS)
	make clean -C $(DIR_LIBFT)
	
fclean: clean
	rm miniRT
	make fclean -C $(DIR_LIBFT)

re: fclean all

.PHONY: all clean fclean re libft mlx
