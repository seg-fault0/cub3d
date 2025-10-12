/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:50:35 by wimam             #+#    #+#             */
/*   Updated: 2025/10/12 12:56:46 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

void angle2vector(t_player *player)
{
	player->dir.x = cos(player->angle);
	player->dir.y = sin(player->angle);
	player->plane.x = -sin(player->angle) * 0.66;
	player->plane.y = cos(player->angle) * 0.66;
}