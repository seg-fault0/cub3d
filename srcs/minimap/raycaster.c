/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:20:01 by wimam             #+#    #+#             */
/*   Updated: 2025/09/12 14:10:11 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define RAY_STEP 0.05
#define RAY_COLOR 0xFF0000
#define TILE_SIZE 20

static void	draw_ray(t_cub *cub, float angle)
{
	float	rx;
	float	ry;
	float	px;
	float	py;

	px = cub->player.xp;
	py = cub->player.yp;
	rx = px;
	ry = py;
	while (cub->parse.map[(int)ry][(int)rx] != '1')
	{
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win,
			(rx - px) * TILE_SIZE + 210,
			(ry - py) * TILE_SIZE + 110,
			RAY_COLOR);
		rx += cos(angle) * RAY_STEP;
		ry += sin(angle) * RAY_STEP;
	}
}

void	minimap_rays(t_cub *cub)
{
	float	start;
	float	end;
	float	angle;
	float	fov;

	fov = 60 * (M_PI / 180);
	start = cub->player.angle - (fov / 2);
	end = cub->player.angle + (fov / 2);
	angle = start;
	while (angle < end)
	{
		draw_ray(cub, angle);
		angle += (fov / 10);
	}
}
