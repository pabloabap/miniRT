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

SRCS		=	./src/main.c \
				./src/mlx_utils/mlx_utils.c \
				src/utils/ft_build_matrix.c \
				src/utils/ft_matrix_mult.c \
				./src/utils/ft_matrix_transpos.c
				
#Object files
DIR_OBJS	= ./build/
OBJS		= $(addprefix $(DIR_OBJS), $(notdir $(patsubst %.c, %.o, $(SRCS))))

HEADERS		= ./include/mini_rt.h

# Directories
DIR_MLX_UTILS = ./src/mlx_utils/
DIR_UTILS = ./src/utils/

all: libft mlx $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lm $(MLXFLAGS) -o $(NAME)

# Creación de directorio objectos si no existen
$(DIR_OBJS):
	mkdir $(DIR_OBJS)

$(DIR_OBJS)%.o: $(DIR_MLX_UTILS)%.c $(HEADERS) Makefile | $(DIR_OBJS)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(DIR_OBJS)%.o: $(DIR_UTILS)%.c $(HEADERS) Makefile | $(DIR_OBJS)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

$(DIR_OBJS)%.o: ./src/main.c $(HEADERS) Makefile | $(DIR_OBJS)
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
