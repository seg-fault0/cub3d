/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:51:32 by wimam             #+#    #+#             */
/*   Updated: 2025/10/11 00:59:41 by mohmajdo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void draw_ceilling(t_cub *cub)
{
	int y;
	int x;
	int index;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			index = (y * WIN_WIDTH) + x;
			cub->img.addr[index] = cub->clr.sky;
			x++;
		}
		y++;
	}
}

static void	ft_check(t_cub *cub)
{
	if (cub->dda.sidedistx < cub->dda.sidedisty)
	{
		cub->dda.sidedistx += cub->dda.deltadistx;
		cub->dda.map_x += cub->dda.step_x;
		cub->dda.side = 0;
	}
	else
	{
		cub->dda.sidedisty += cub->dda.deltadisty;
		cub->dda.map_y += cub->dda.step_y;
		cub->dda.side = 1;
	}
}

void	put_pixel(t_imgs *img,int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		img->addr[y * img->ppl + x] = color;
}

void	check_raydir(t_dda *ray, t_player *player)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedistx = (player->xp - ray->map_x) * ray->deltadistx;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedistx = (ray->map_x + 1.0 - player->xp) * ray->deltadistx;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedisty = (player->yp - ray->map_y) * ray->deltadisty;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedisty = (player->yp - ray->map_y + 1) * ray->deltadisty;
	}
}

void calc_line_height(t_dda *ray)
{
	if (ray->side == 0)
		ray->walldist = ray->sidedistx - ray->deltadistx;
	else
		ray->walldist = ray->sidedisty - ray->deltadisty;
	if (ray->walldist < 0.0001)
		ray->walldist = 0.0001;
	ray->line_height = (int)(WIN_HEIGHT / ray->walldist);
	ray->draw_start = WIN_HEIGHT / 2 - ray->line_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}


void	draw_wall_stripe(t_cub *cub, int x)
{
	int  y;
	int  color;
	double wall_x;

	cub->dda.tex_step = 1.0 * TEXTERE_HEIGHT / cub->dda.line_height;
	cub->dda.tex_pos = (cub->dda.draw_start - WIN_HEIGHT / 2 
				+ cub->dda.line_height / 2) * cub->dda.tex_step;
	if (cub->dda.side == 0)
	{
		if (cub->dda.raydir_x > 0)
			cub->dda.tex_num = 5;
		else
			cub->dda.tex_num = 6;
	}
	else
	{
		if (cub->dda.raydir_y > 0)
			cub->dda.tex_num = 4;
		else
			cub->dda.tex_num = 3;
	}
	if (cub->dda.side == 0)
		wall_x = cub->player.yp + cub->dda.walldist * cub->dda.raydir_y;
	else
		wall_x = cub->player.xp + cub->dda.walldist * cub->dda.raydir_x;
	wall_x -= floor(wall_x);
	int tex_x = (int)(wall_x * (double)TEXTERE_WIDHT);
	if (cub->dda.side == 0 && cub->dda.raydir_x > 0)
		tex_x = TEXTERE_WIDHT - tex_x - 1;
	if (cub->dda.side == 1 && cub->dda.raydir_y < 0)
		tex_x = TEXTERE_WIDHT - tex_x - 1;
	if (tex_x < 0) tex_x = 0;
	if (tex_x >= TEXTERE_WIDHT) tex_x = TEXTERE_WIDHT - 1;
	y = cub->dda.draw_start;
	while (y < cub->dda.draw_end)
	{
		cub->dda.tex_y = (int)cub->dda.tex_pos & (TEXTERE_HEIGHT - 1);
		cub->dda.tex_pos += cub->dda.tex_step;
		color = cub->textures[cub->dda.tex_num][TEXTERE_WIDHT * cub->dda.tex_y + tex_x];
		if (cub->dda.side == 1)
			color = (color >> 1) & 8355711;
		put_pixel(&cub->img, x, y, color);
		y++;
	}
}

void	calc_wall_texture_x(t_dda *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wall_x = player->yp + ray->walldist * ray->raydir_y;
	else
		ray->wall_x = player->xp + ray->walldist * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TEXTERE_WIDHT);
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = TEXTERE_WIDHT - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = TEXTERE_WIDHT - ray->tex_x - 1;
	if (ray->tex_x < 0)
        ray->tex_x = 0;
    if (ray->tex_x >= TEXTERE_WIDHT)
        ray->tex_x = TEXTERE_WIDHT - 1;
}

void	wall_cast(t_cub *cub)
{
	int	hit;
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(&cub->dda, &cub->player, x);
		check_raydir(&cub->dda, &cub->player);
		hit = 0;
		while (hit == 0)
		{
			ft_check(cub);
			if (cub->dda.map_x >= 0 && cub->dda.map_y >= 0 &&
				cub->dda.map_y < cub->parse.max_map_y &&
				cub->dda.map_x < ft_strlen(cub->parse.map[cub->dda.map_y]) &&
    			cub->parse.map[cub->dda.map_y][cub->dda.map_x] == '1')
    				hit = 1;
		}
		calc_line_height(&cub->dda);
		calc_wall_texture_x(&cub->dda,&cub->player);
		draw_wall_stripe(cub, x);
		x++;
	}
	return ;
}

void	init_floor_ray(t_cub *cub, int y)
{
	cub->rfloor.rayDirX0 = cub->player.dir_x - cub->player.plane_x;
	cub->rfloor.rayDirY0 = cub->player.dir_y - cub->player.plane_y;
	cub->rfloor.rayDirX1 = cub->player.dir_x + cub->player.plane_x;
	cub->rfloor.rayDirY1 = cub->player.dir_y + cub->player.plane_y;
	cub->rfloor.p = y - WIN_HEIGHT / 2;
	cub->rfloor.posz = 0.5 * WIN_HEIGHT;
	cub->rfloor.rowDistance = cub->rfloor.posz / cub->rfloor.p;
	cub->rfloor.floor_sx = cub->rfloor.rowDistance * (cub->rfloor.rayDirX1 - cub->rfloor.rayDirX0) / WIN_HEIGHT;
	cub->rfloor.floor_sy = cub->rfloor.rowDistance * (cub->rfloor.rayDirY1 - cub->rfloor.rayDirY0) / WIN_HEIGHT;
	cub->rfloor.floor_x = cub->player.xp + cub->rfloor.rowDistance * cub->rfloor.rayDirX0;
	cub->rfloor.floor_y = cub->player.yp + cub->rfloor.rowDistance * cub->rfloor.rayDirY0;
}

void draw_floor(t_cub *cub)
{
    int y;
    int x;
    int index;

    y = WIN_HEIGHT / 2;
    while (y < WIN_HEIGHT)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            index = y * cub->img.ppl + x;
            cub->img.addr[index] = cub->clr.floor;
            x++;
        }
        y++;
    }
}

void	floor_cast(t_cub *cub)
{
	int	y;
	int	x;
	int	color;
    int	floor_texture;

	y = 0;
	floor_texture = 2;
	while (y < WIN_HEIGHT)
	{
		init_floor_ray(cub, y);
		x = 0;
		while(x < WIN_WIDTH)
		{
			cub->rfloor.cell_x = (int)cub->rfloor.floor_x;
			cub->rfloor.cell_y = (int)cub->rfloor.floor_y;
			cub->rfloor.tx = (int)(TEXTERE_WIDHT * (cub->rfloor.floor_x - cub->rfloor.cell_x)) & (TEXTERE_WIDHT - 1);
			cub->rfloor.ty = (int)(TEXTERE_HEIGHT * (cub->rfloor.floor_y - cub->rfloor.cell_y)) & (TEXTERE_HEIGHT - 1);
			color = cub->textures[cub->dda.tex_num][TEXTERE_WIDHT * cub->dda.tex_y + cub->dda.tex_x];
			color = (color >> 1) & 8355711;
			put_pixel(&cub->img, x, y, color);
			cub->rfloor.floor_x += cub->rfloor.floor_sx;
			cub->rfloor.floor_y += cub->rfloor.floor_sy;
			x++;
		}
		y++;
	}
}

void clear_image(t_cub *cub)
{
	int i;
	int total_pixels;

	total_pixels = WIN_WIDTH * WIN_HEIGHT;
	i = 0;
	while (i < total_pixels)
	{
		cub->img.addr[i] = 0;
		i++;
	}
}

void	world_raycaster(t_cub *cub)
{
	clear_image(cub);
	draw_ceilling(cub);
	draw_floor(cub);
	// floor_cast(cub);
	wall_cast(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->img.img, 0, 0);
	return ;
}
