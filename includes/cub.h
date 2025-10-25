/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:02:44 by wimam             #+#    #+#             */
/*   Updated: 2025/10/25 16:01:38 by wimam            ###   ########.fr       */
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
# include <time.h>
# include <math.h>

// win_dimensions
# define WIN_WIDTH 1800
# define WIN_HEIGHT 1000
# define TEXTERE_HEIGHT 64
# define TEXTERE_WIDHT  64 
//key_code
# define ESC_KEY 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100 
# define E_KEY 101
# define R_ARR 65363
# define L_ARR 65361

//ERR_MSG
# define ERR_MALLOC 1
# define ERR_MLX 2
# define ERR_WIN 3
# define ERR_AC 4
# define ERR_OPEN 5
# define ERR_MAP_SIZE 6
# define ERR_IMG 7
# define ERR_ELMT_NF 8
# define ERR_CLR_FORMAT 9
# define ERR_MAP_BORDER 10
# define ERR_MLTPL_PLYR 11
# define ERR_PLYR_NF 12

//gnl
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//SPEED
# define PLAYER_SPEED 0.1
# define ROTATION_SPEED 0.06
# define MOUSE_SPEED 0.01
# define COLLISION_RADIUS 0.2f

//other
# define MAX_FILE_SIZE 150
# define DOOR_RADIOUS 3

//img_paths
# define MM_FRAME_PATH "./textures/minimap/frame.xpm"
# define MM_WALL_PATH "./textures/minimap/mm_wall.xpm"
# define MM_FLOOR_PATH "./textures/minimap/mm_floor.xpm"
# define MM_DOOR_PATH "./textures/minimap/mm_door.xpm"
# define MM_DEMON_PATH "./textures/minimap/mm_demon.xpm"
# define PLAYER_PATH "./textures/player.xpm"
# define DOOR_PATH "./textures/walls/door.xpm"

//img
# define TEXTURE_NBR 6
# define DEMON_NBR 7
# define TRANSP 0xFF00FF

/*
*******************************************
*************   VECTOR2  ******************
*******************************************
*/
typedef struct s_fvector2
{
	float	x;
	float	y;
}t_fvector2;

typedef struct s_ivector2
{
	int	x;
	int	y;
}t_ivector2;

/*
****************************************
************     DDA    ****************
****************************************
*/

typedef struct s_tex
{
	int		x;
	int		y;
	float	pos;
	float	step;
}t_tex;

typedef struct s_draw
{
	int	start;
	int	end;
}t_draw;

typedef struct s_wall
{
	float	dist;
	int		x;
}t_wall;

typedef struct s_dda
{
	t_ivector2	map;
	t_fvector2	ray_dir;
	t_fvector2	delta;
	t_fvector2	side_dist;
	t_ivector2	step;
	t_tex		tex;
	t_draw		draw;
	t_wall		wall;
	double		camera;
	int			side;
	int			line_height;
	int			tex_num;
}t_dda;

/*
********************************************
**************   IMG ***********************
********************************************
*/

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ppl;
	int		size_line;
	int		endian;
	int		height;
	int		width;
	int		tex_size;
}t_img;

typedef struct s_imgs
{
	t_img	display;
	t_img	mm_frame;
	t_img	mm_wall;
	t_img	mm_floor;
	t_img	mm_demon;
	t_img	mm_door;
	t_img	n_wall;
	t_img	s_wall;
	t_img	e_wall;
	t_img	w_wall;
	t_img	player;
	t_img	door;
	t_img	demon[DEMON_NBR];
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
	bool	e;
	bool	esq;
	bool	r_arr;
	bool	l_arr;
}t_key;

typedef struct s_sprite
{
	double	x;
	double	y;
	int		texture;
	int		type;
}	t_sprite;

typedef struct s_sprite_data
{
	t_sprite	*sprites;
	int			count;
	double		*zbuffer;
	int			*order;
	double		*distance;
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_y;
	int			draw_end_y;
	int			draw_start_x;
	int			draw_end_x;
	int			stripe;
}	t_sprite_data;

typedef struct s_player
{
	t_fvector2	pos;
	t_fvector2	dir;
	t_fvector2	plane;
	int			has_move;
	float		angle;
}t_player;

typedef struct s_clr
{
	int	floor;
	int	sky;
}t_clr;

typedef struct s_parse
{
	char	**file;
	char	*sky_clr;
	char	*floor_clr;
	char	*n_wall;
	char	*s_wall;
	char	*e_wall;
	char	*w_wall;
	char	**map;
	int		max_map_y;
}t_parse;

typedef struct s_cub
{
	t_parse		parse;
	t_mlx		mlx;
	t_key		key;
	t_imgs		img;
	t_clr		clr;
	int			*textures[TEXTURE_NBR];
	t_player	player;
	t_sprite_data	sprites;
	t_dda		dda;
}t_cub;

//core
bool	setup_cub(t_cub *cub, char **av);
void	luncher(t_cub *cub);
int		ft_exit(t_cub *cub, int code);
void	err_msg(int msg);

//init
bool	ft_mlx_init(t_mlx *mlx);
bool	parse(t_cub *cub, char *path);

//img
void	imgs_bzero(t_imgs *imgs);
bool	img_init(t_cub *cub);
void	mlx_xpm(void *mlx, char *path, t_img *img);
bool	texture_loader(t_cub *cub);
int		*load_tex_animation(t_img demon[DEMON_NBR]);
void	mlx_xpm_animaton(void *mlx, t_img demon[DEMON_NBR]);
void	free_animation(void *mlx, t_img demon[DEMON_NBR]);

//draw
void	draw_img_to_img(t_img *dst, t_img *src, int px, int py);
void	put_pixel_to_img(t_img *img, int x, int y, int color);

//free
void	free_mlx(t_mlx mlx);
void	free_img(t_cub *cub);

//player
void	player(t_cub *cub);//main
bool	player_init(t_cub *cub);
void	player_mouvement(t_cub *cub);
void	player_rotation(t_cub *cub);

//door
void	door(t_cub *cub);

//demon
bool	demon_init(t_cub *cub);

//engine
int		game_cycle(t_cub *cub);//main

//parser geter
bool	read_file(t_cub *cub, char *path);
bool	get_textures(t_cub *cub);
bool	get_clr_format(t_cub *cub);
bool	get_map(t_cub *cub);

//parser checker
bool	allowed_char(char c);
bool	check_map_border(t_cub *cub);
bool	check_repeated_map_chars(t_cub *cub);

//raycasting
void	render_world(t_cub *cub); //main
void	angle2vector(t_player *player);
void	calc_line_height(t_dda *ray);
void	calc_wall_texture_x(t_dda *ray, t_player *player);
void	init_ray(t_dda *ray, t_player *player, int x);
void	wall_cast(t_cub *cub);
void	draw_door(t_cub *cub, int x);
void	ft_check(t_cub *cub);
void	check_raydir(t_dda *ray, t_player *player);
void	render_sprites(t_cub *cub);
void	sort_sprites(t_cub *cub);
bool	init_sprite_system(t_cub *cub);

//minimap
void	minimap(t_cub *cub);//main
void	minimap_rays(t_cub *cub);
void	draw_walls(t_cub *cub);

//input
int		key_press(int key, t_key *keys);
int		key_release(int key, t_key *keys);
int		mouse_move(int x, int y, t_player *player);

//libft
void	*ft_memset(void *b, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
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