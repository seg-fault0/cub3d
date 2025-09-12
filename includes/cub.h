/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:02:44 by wimam             #+#    #+#             */
/*   Updated: 2025/09/12 08:37:13 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

// includes
# include "mlx.h"
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

// win_dimensions
# define WIN_WIDTH 2500
# define WIN_HEIGHT 1200

//key_code
# define ESC_KEY 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100 

//ERR_MSG
# define ERR_MALLOC 1
# define ERR_MLX 2
# define ERR_WIN 3
# define ERR_AC 4
# define ERR_OPEN 5
# define ERR_MAP_SIZE 6
# define ERR_IMG 7

//gnl
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//other
# define MAX_MAP_SIZE 100

//img_paths
# define MM_FRAME_PATH "./textures/frame.xpm"
# define MM_WALL_PATH "./textures/mm_wall.xpm"
# define MM_FLOOR_PATH "./textures/mm_floor.xpm"
# define PLAYER_PATH "./textures/player.xpm"

//img
# define MM_FRAME 1
# define MM_WALL 2
# define MM_FLOOR 3
# define PLAYER 4

//structs
typedef struct s_img
{
	void	*p;
	int		height;
	int		width;
}t_img;

typedef struct s_imgs
{
	t_img	mm_frame;
	void	*player;
	void	*mm_wall;
	void	*mm_floor;
}t_imgs;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}t_mlx;

typedef struct s_key
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	esq;
}t_key;

typedef struct s_player
{
	float	xp;
	float	yp;
}t_player;

typedef struct s_parse
{
	char	**map;
	int		max_map_y;
}t_parse;

typedef struct s_cub
{
	t_mlx		mlx;
	t_key		key;
	t_imgs		img;
	t_player	player;
	t_parse		parse;
}t_cub;

//core
bool	setup_cub(t_cub *cub, char **av);
void	luncher(t_cub *cub);
int		ft_exit(t_cub *cub, int code);
void	err_msg(int msg);

//init
bool	ft_mlx_init(t_mlx *mlx);
bool	map_init(t_cub *cub, char *path);

//img
void	imgs_bzero(t_imgs *imgs);
bool	img_init(t_cub *cub);

//mlx
void	mlx_draw(t_cub *cub, int img, int x, int y);

//free
void	free_mlx(t_mlx mlx);
void	free_img(t_cub *cub);

//player
void	player(t_cub *cub);
void	player_mouvement(t_cub *cub);
bool	player_init(t_cub *cub);

//engine
int		game_cycle(t_cub *cub);

//parser
char	**read_map(char *path);

//minimap
void	minimap(t_cub *cub);
void	draw_walls(t_cub *cub);

//input
int		key_press(int key, t_key *keys);
int		key_release(int key, t_key *keys);

//libft
void	*ft_memset(void *b, int c, size_t len);
int		ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(char *str);
int		get_arr_size(char **arr);
char	**get_2darr_cp(char **arr);
void	print_arr(char **arr);
void	free2(char **arr);

//gnl
char	*ft_strljoin(char *s1, char *s2, int size);
int		ft_new_line_check(char *str);
char	*ft_init(char *str);
char	*get_next_line(int fd);

#endif