// CABECERA

NAME		= miniRT

DIR_LIBFT	= ./lib/libft
LIBFT_AR	= ./lib/libft/libft.a

#___MLX___
MLX_DIR		= ./lib/minilibx-linux/
MLX			= libmlx.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -lmlx -lXext -lx11
LIBFT		= -L$(DIR_LIBFT) -lft

INCLUDE		= -Iinclude -I$(LIBFT_DIR) -I$(MLX_DIR)

SRCS		= #INCLUIR LOS FICHEROS .ca.c

#Object files
OBJS		= $(addprefix $(OBJS_DIR), $(notdir $(patsubst %.c, %.o, $(SRCS))))

HEADERS		= ./include/mini_rt.h

all: libft mlx $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lm $(MLXFLAGS) -o $(NAME)

# Creación de directorio objectos si no existen
$(OBJS_DIR):
	mkdir $(OBJS_DIR)


$(OBJS_DIR)%.o: $(SRC) $(HEADERS) Makefile | $(OBJS_DIR)
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

mlx:
	@make -C $(DIR_MLX) all

libft:
	$(MAKE) -C $(DIR_LIBFT)

clean:
	rm -rf $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)
	
fclean: clean
	rm miniRT
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re libft mlx
