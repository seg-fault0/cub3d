/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:51:32 by wimam             #+#    #+#             */
/*   Updated: 2025/10/06 05:48:43 by mohmajdo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

// void my_mlx_pixel_put(t_imgs *img, int x, int y, int color)
// {
// 	char *dst;

// 	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void	update_draw(t_cub *cub, t_dda *ray, int x)
// {
// 	int y;
// 	int color;

// 	// Simple color-based drawing first to debug
// 	if (ray->side == 0 && ray->raydir_x > 0)
// 		color = 0xFF0000;  // Red - East wall
// 	else if (ray->side == 0 && ray->raydir_x < 0)
// 		color = 0x00FF00;  // Green - West wall
// 	else if (ray->side == 1 && ray->raydir_y > 0)
// 		color = 0x0000FF;  // Blue - South wall
// 	else
// 		color = 0xFFFF00;  // Yellow - North wall

// 	y = ray->draw_start;
// 	while (y < ray->draw_end)
// 	{
// 		my_mlx_pixel_put(&cub->img, x, y, color);
// 		y++;
// 	}
// }

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

void	calc_line_height(t_dda *ray)
{
	if (ray->side == 0)
		ray->walldist = ray->sidedistx - ray->deltadistx;
	else
		ray->walldist = ray->sidedisty - ray->deltadisty;
	ray->line_height = (int)(WIN_HEIGHT / ray->walldist);
	ray->draw_start = WIN_HEIGHT / 2 - ray->line_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
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
    			cub->parse.map[cub->dda.map_y][cub->dda.map_x] != '0')
    				hit = 1;
		}
		calc_line_height(&cub->dda);
		update_draw(cub, &cub->dda, x);
		x++;
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->img.img, 0, 0);
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
void	floor_cast(t_cub *cub)
{
	int	y;
	int	x;
	int	color;
    int	floor_texture;
    int	ceiling_texture;

	y = 0;
	floor_texture = 2;
	ceiling_texture = 7;
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
			cub->rfloor.floor_x += cub->rfloor.floor_sx;
			cub->rfloor.floor_y += cub->rfloor.floor_sy;
			color = cub->textures[floor_texture][TEXTERE_WIDHT * cub->rfloor.ty + cub->rfloor.tx];
			color = (color >> 1) & 8355711;
			put_pixel(&cub->img, x, y, color);
			//draw ceilling but need textere;
			cub->rfloor.floor_x += cub->rfloor.floor_sx;
            cub->rfloor.floor_y += cub->rfloor.floor_sy;
			x++;
		}
		y++;
	}
}

void	world_raycaster(t_cub *cub)
{
	floor_cast(cub);
	wall_cast(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->img.img, 0, 0);
	return ;
}
