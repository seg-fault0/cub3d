SRCS = srcs/core/main.c	\

OBJS	= $(SRCS:srcs/%.c=objs/%.o)

NAME	= cub3d

FLAGS	= -Wall -Wextra -Werror

I		= -I includes/

L = -L mlxlib/ -lmlx_Linux -lXext -lX11

all: mlx $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) $(L) -o $(NAME)

objs/%.o: srcs/%.c includes/cub3d.h | objs/
	@mkdir -p $(@D)
	cc -c $(I) $(FLAGS) $< -o $@

objs/:
	mkdir -p objs

clean:
	rm -rf objs/

fclean: clean
	rm -f $(NAME)
	rm -f includes/mlx.h mlxlib/libmlx_Linux.a

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