/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:42:09 by wimam             #+#    #+#             */
/*   Updated: 2025/10/11 00:58:34 by mohmajdo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	imgs_bzero(t_imgs *imgs)
{
	ft_memset(&imgs->mm_frame, 0, sizeof(t_img));
	ft_memset(imgs, 0, sizeof(imgs));
}

void	free_img(t_cub *cub)
{
	if (cub->img.mm_frame.p)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_frame.p);
	if (cub->img.mm_wall)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_wall);
	if (cub->img.mm_floor)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_floor);
	if (cub->img.n_wall)
		mlx_destroy_image(cub->mlx.mlx, cub->img.n_wall);
	if (cub->img.s_wall)
		mlx_destroy_image(cub->mlx.mlx, cub->img.s_wall);
	if (cub->img.e_wall)
		mlx_destroy_image(cub->mlx.mlx, cub->img.e_wall);
	if (cub->img.w_wall)
		mlx_destroy_image(cub->mlx.mlx, cub->img.w_wall);
	if (cub->img.img)
		mlx_destroy_image(cub->mlx.mlx, cub->img.img);
}

void	*mlx_xpm(void *mlx, char *path, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx, path, width, height));
}

bool	init_scr_img(t_cub *cub)
{
	cub->img.img = mlx_new_image(cub->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cub->img.img)
		return (false);
	cub->img.addr = (int *)mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel, &cub->img.size_line, &cub->img.endian);
	if (!cub->img.addr)
		return (false);
	cub->img.ppl = cub->img.size_line / sizeof(int);
	return (true);
}

int *load_tex(void *mlx, char *path)
{
    t_imgs   tex;
    int     *buffer;
    int     x, y;

    tex.img = mlx_xpm_file_to_image(mlx, path, &tex.width, &tex.height);
    if (!tex.img)
        return (NULL);
    
    tex.addr = (int *)mlx_get_data_addr(tex.img, &tex.bits_per_pixel, &tex.size_line, &tex.endian);
    if (!tex.addr)
    {
        mlx_destroy_image(mlx, tex.img);
        return (NULL);
    }
    buffer = malloc(sizeof(int) * TEXTERE_HEIGHT * TEXTERE_WIDHT);
    if (!buffer)
    {
        mlx_destroy_image(mlx, tex.img);
        return (NULL);
    }  
    int line_len = tex.size_line / (tex.bits_per_pixel / 8);
    y = 0;
    while (y < tex.height && y < TEXTERE_HEIGHT)
    {
        x = 0;
        while (x < tex.width && x < TEXTERE_WIDHT)
        {
            buffer[y * TEXTERE_WIDHT + x] = tex.addr[y * line_len + x];
            x++;
        }
        y++;
    }
    
    mlx_destroy_image(mlx, tex.img);
    return (buffer);
}

bool	ft_img_init(t_cub *cub)
{
	cub->textures = malloc(sizeof(int *) * 7);
	if (!cub->textures)
		return (false);
	cub->textures[0] = load_tex(cub->mlx.mlx, MM_FRAME_PATH);
	cub->textures[1] = load_tex(cub->mlx.mlx, MM_WALL_PATH);
	cub->textures[2] = load_tex(cub->mlx.mlx, MM_FLOOR_PATH);
	cub->textures[3] = load_tex(cub->mlx.mlx, cub->parse.n_wall);
	cub->textures[4] = load_tex(cub->mlx.mlx, cub->parse.s_wall);
	cub->textures[5] = load_tex(cub->mlx.mlx, cub->parse.e_wall);
	cub->textures[6] = load_tex(cub->mlx.mlx, cub->parse.w_wall);
	if (!cub->textures[0] || !cub->textures[1] || !cub->textures[2]
		|| !cub->textures[3] || !cub->textures[4] || !cub->textures[5]
		|| !cub->textures[6])
		return (err_msg(ERR_IMG), false);
	return (true);
}


bool	img_init(t_cub *cub)
{
	void	*mlx;
	int		size;

	mlx = cub->mlx.mlx;
	cub->img.mm_frame.p = mlx_xpm(mlx, MM_FRAME_PATH, &cub->img.mm_frame.width, &cub->img.mm_frame.height);
	cub->img.mm_wall = mlx_xpm(mlx, MM_WALL_PATH, &size, &size);
	cub->img.mm_floor = mlx_xpm(mlx, MM_FLOOR_PATH, &size, &size);
	cub->img.n_wall = mlx_xpm(mlx, cub->parse.n_wall, &size, &size);
	cub->img.s_wall = mlx_xpm(mlx, cub->parse.s_wall, &size, &size);
	cub->img.e_wall = mlx_xpm(mlx, cub->parse.e_wall, &size, &size);
	cub->img.w_wall = mlx_xpm(mlx, cub->parse.w_wall, &size, &size);
	if (!cub->img.mm_frame.p || !cub->img.mm_wall || !cub->img.mm_floor
		|| !cub->img.n_wall || !cub->img.s_wall || !cub->img.e_wall
		|| !cub->img.w_wall)
		return (err_msg(ERR_IMG), false);
	return (true);
}
