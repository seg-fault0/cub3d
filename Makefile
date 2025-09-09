SRCS = 	srcs/core/main.c		\
		srcs/core/input.c		\
		srcs/core/luncher.c		\
		srcs/core/exit.c		\
		srcs/core/init.c		\
		srcs/gnl/gnl.c			\
		srcs/gnl/gnl_utils.c	\
		srcs/core/err_msg.c		\
		srcs/libft/memset.c		\
		srcs/libft/strlen.c		\
		srcs/libft/strdup.c		\
		srcs/libft/putstr_fd.c	\
		srcs/map/init.c			\
		srcs/map/reader.c		\
		srcs/map/free.c			\
		srcs/mlx/init.c			\
		srcs/mlx/free.c			\

OBJS	= $(SRCS:srcs/%.c=objs/%.o)

NAME	= cub3d

FLAGS	= -g #-Wall -Wextra -Werror

I		= -I includes/

L = -L mlxlib/ -lmlx_Linux -lXext -lX11

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

ffclean:
	rm -fr includes/mlx.h
	rm -fr mlxlib/libmlx_Linux.a