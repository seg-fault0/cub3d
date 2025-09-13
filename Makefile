SRCS = 	srcs/core/main.c			\
		srcs/core/exit.c			\
		srcs/core/setup.c			\
		srcs/engine/input_detector.c\
		srcs/engine/game_cycle.c	\
		srcs/engine/luncher.c		\
		srcs/gnl/gnl.c				\
		srcs/gnl/gnl_utils.c		\
		srcs/core/err_msg.c			\
		srcs/libft/memset.c			\
		srcs/libft/strlen.c			\
		srcs/libft/strdup.c			\
		srcs/libft/arrays.c			\
		srcs/libft/memcmp.c			\
		srcs/libft/putstr_fd.c		\
		srcs/minimap/main.c			\
		srcs/minimap/raycaster.c	\
		srcs/minimap/walls.c		\
		srcs/mlx/img.c				\
		srcs/mlx/draw.c				\
		srcs/mlx/mlx.c				\
		srcs/parser/main.c			\
		srcs/parser/reader.c		\
		srcs/parser/map.c			\
		srcs/parser/textures.c		\
		srcs/player/main.c			\
		srcs/player/init.c			\
		srcs/player/mouvement.c		\
		srcs/player/collisions.c	\
		srcs/render/main.c			\

OBJS	= $(SRCS:srcs/%.c=objs/%.o)

NAME	= cub3d

FLAGS	= -g #-Wall -Wextra -Werror

I		= -I includes/

L = -L mlxlib/ -lmlx_Linux -lXext -lX11 -lm

all: mlx $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) $(L) -o $(NAME)

objs/%.o: srcs/%.c includes/cub.h | objs/
	@mkdir -p $(@D)
	cc -c $(I) $(FLAGS) $< -o $@

objs/:
	mkdir -p objs

clean:
	rm -rf objs/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

mlx:
	@if [ ! -f mlxlib/libmlx_Linux.a ] || [ ! -f includes/mlx.h ]; then \
		tar -xvzf mlxlib/mlx.tgz && \
		cd minilibx-linux && make && \
		cd .. && \
		mv -f minilibx-linux/libmlx_Linux.a mlxlib/ && \
		mv -f minilibx-linux/mlx.h includes/ && \
		rm -fr minilibx-linux; \
	fi

ffclean: fclean
	rm -fr includes/mlx.h
	rm -fr mlxlib/libmlx_Linux.a