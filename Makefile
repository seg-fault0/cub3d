SRCS = 	srcs/core/main.c						\
		srcs/core/exit.c						\
		srcs/core/setup.c						\
		srcs/engine/input_detector.c			\
		srcs/engine/game_cycle.c				\
		srcs/engine/mlx.c						\
		srcs/engine/luncher.c					\
		srcs/gnl/gnl.c							\
		srcs/gnl/gnl_utils.c					\
		srcs/core/err_msg.c						\
		srcs/libft/memset.c						\
		srcs/libft/is_space.c					\
		srcs/libft/strlen.c						\
		srcs/libft/strdup.c						\
		srcs/libft/arrays.c						\
		srcs/libft/memcmp.c						\
		srcs/libft/putstr_fd.c					\
		srcs/minimap/raycaster.c				\
		srcs/minimap/main.c						\
		srcs/minimap/walls.c					\
		srcs/graphic/animation.c 				\
		srcs/graphic/draw.c						\
		srcs/graphic/free.c						\
		srcs/graphic/img.c						\
		srcs/graphic/textures.c					\
		srcs/parser/main.c						\
		srcs/parser/geters/file.c				\
		srcs/parser/geters/map.c				\
		srcs/parser/geters/colors.c				\
		srcs/parser/geters/textures.c			\
		srcs/parser/checkers/map_border.c		\
		srcs/parser/checkers/repeated_chars.c	\
		srcs/player/main.c						\
		srcs/player/init.c						\
		srcs/player/mouvement.c					\
		srcs/player/rotation.c					\
		srcs/render/main.c						\
		srcs/render/init.c						\
		srcs/render/raycaster.c					\
		srcs/render/calculator.c				\
		srcs/render/checker.c					\
		srcs/render/door.c						\
		srcs/render/spirites.c					\
		srcs/render/draw_spirites.c				\
		srcs/bonus/door.c						\
		srcs/bonus/demon.c						\

OBJS	= $(SRCS:srcs/%.c=objs/%.o)

NAME	= cub3d

FLAGS	= -g -Wall -Wextra -Werror -g

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