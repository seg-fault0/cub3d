/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:51:32 by wimam             #+#    #+#             */
/*   Updated: 2025/10/12 12:48:58 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_check(t_cub *cub)
{
	if (cub->dda.sideDist.x < cub->dda.sideDist.y)
	{
		cub->dda.sideDist.x += cub->dda.delta.x;
		cub->dda.map.x += cub->dda.step.x;
		cub->dda.side = 0;
	}
	else
	{
		cub->dda.sideDist.y += cub->dda.delta.y;
		cub->dda.map.y += cub->dda.step.y;
		cub->dda.side = 1;
	}
}

void	check_raydir(t_dda *ray, t_player *player)
{
	if (ray->rayDir.x < 0)
	{
		ray->step.x = -1;
		ray->sideDist.x = (player->pos.x - ray->map.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sideDist.x = (ray->map.x + 1 - player->pos.x) * ray->delta.x;
	}
	if (ray->rayDir.y < 0)
	{
		ray->step.y = -1;
		ray->sideDist.y = (player->pos.y - ray->map.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sideDist.y = (ray->map.y + 1 - player->pos.y) * ray->delta.y;
	}
}

void calc_line_height(t_dda *ray)
{
	if (ray->side == 0)
		ray->wall.dist = ray->sideDist.x - ray->delta.x;
	else
		ray->wall.dist = ray->sideDist.y - ray->delta.y;
	if (ray->wall.dist < 0.0001)
		ray->wall.dist = 0.0001;
	ray->line_height = (int)(WIN_HEIGHT / ray->wall.dist);
	ray->draw.start = WIN_HEIGHT / 2 - ray->line_height / 2;
	if (ray->draw.start < 0)
		ray->draw.start = 0;
	ray->draw.end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw.end >= WIN_HEIGHT)
		ray->draw.end = WIN_HEIGHT - 1;
}


void	draw_wall_stripe(t_cub *cub, int x)
{
	int  y;
	int  color;
	double wall_x;

	cub->dda.tex.step = 1.0 * TEXTERE_HEIGHT / cub->dda.line_height;
	cub->dda.tex.pos = (cub->dda.draw.start - WIN_HEIGHT / 2 
				+ cub->dda.line_height / 2) * cub->dda.tex.step;
	if (cub->dda.side == 0)
	{
		if (cub->dda.rayDir.x > 0)
			cub->dda.tex_num = 5;
		else
			cub->dda.tex_num = 6;
	}
	else
	{
		if (cub->dda.rayDir.y > 0)
			cub->dda.tex_num = 4;
		else
			cub->dda.tex_num = 3;
	}
	if (cub->dda.side == 0)
		wall_x = cub->player.pos.y + cub->dda.wall.dist * cub->dda.rayDir.y;
	else
		wall_x = cub->player.pos.y + cub->dda.wall.dist * cub->dda.rayDir.x;
	wall_x -= floor(wall_x);
	int tex_x = (int)(wall_x * (double)TEXTERE_WIDHT);
	if (cub->dda.side == 0 && cub->dda.rayDir.x > 0)
		tex_x = TEXTERE_WIDHT - tex_x - 1;
	if (cub->dda.side == 1 && cub->dda.rayDir.y < 0)
		tex_x = TEXTERE_WIDHT - tex_x - 1;
	if (tex_x < 0) tex_x = 0;
	if (tex_x >= TEXTERE_WIDHT) tex_x = TEXTERE_WIDHT - 1;
	y = cub->dda.draw.start;
	while (y < cub->dda.draw.end)
	{
		cub->dda.tex.y = (int)cub->dda.tex.pos & (TEXTERE_HEIGHT - 1);
		cub->dda.tex.pos += cub->dda.tex.step;
		color = cub->textures[cub->dda.tex_num][TEXTERE_WIDHT * cub->dda.tex.y + tex_x];
		if (cub->dda.side == 1)
			color = (color >> 1) & 8355711;
		put_pixel_to_img(&cub->img.display, x, y, color);
		y++;
	}
}

void	calc_wall_texture_x(t_dda *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wall.x = player->pos.y + ray->wall.dist * ray->rayDir.y;
	else
		ray->wall.x = player->pos.x + ray->wall.dist * ray->rayDir.x;
	ray->wall.x -= floor(ray->wall.x);
	ray->tex.x = (int)(ray->wall.x * (double)TEXTERE_WIDHT);
	if (ray->side == 0 && ray->rayDir.x > 0)
		ray->tex.x = TEXTERE_WIDHT - ray->tex.x - 1;
	if (ray->side == 1 && ray->rayDir.y < 0)
		ray->tex.x = TEXTERE_WIDHT - ray->tex.x - 1;
	if (ray->tex.x < 0)
        ray->tex.x = 0;
    if (ray->tex.x >= TEXTERE_WIDHT)
        ray->tex.x = TEXTERE_WIDHT - 1;
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
			if (cub->dda.map.x >= 0 && cub->dda.map.y >= 0 &&
				cub->dda.map.y < cub->parse.max_map_y &&
				cub->dda.map.x < ft_strlen(cub->parse.map[cub->dda.map.y]) &&
    			cub->parse.map[cub->dda.map.y][cub->dda.map.x] == '1')
    				hit = 1;
		}
		calc_line_height(&cub->dda);
		calc_wall_texture_x(&cub->dda,&cub->player);
		draw_wall_stripe(cub, x);
		x++;
	}
	return ;
}

void update_vectors_from_angle(t_player *player)
{
	player->dir.x = cos(player->angle);
	player->dir.y = sin(player->angle);
	player->plane.x = -sin(player->angle) * 0.66;
	player->plane.y = cos(player->angle) * 0.66;
}

void	world_raycaster(t_cub *cub)
{
	update_vectors_from_angle(&cub->player);;
	wall_cast(cub);
	return ;
}
