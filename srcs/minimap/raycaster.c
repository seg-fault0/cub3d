/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:20:01 by wimam             #+#    #+#             */
/*   Updated: 2025/10/13 14:01:27 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define RAY_STEP 0.05
#define RAY_COLOR 0xFF0000
#define TILE_SIZE 20

static bool	ray_mm_border(t_fvector2 pos, t_fvector2 ray)
{
	t_fvector2	screen;

	screen.x = (ray.x - pos.x) * TILE_SIZE + 210;
	screen.y = (ray.y - pos.y) * TILE_SIZE + 110;
	if (screen.x >= 390 || screen.y >= 210)
		return (true);
	return (false);
}

static void	draw_ray(t_cub *cub, float angle)
{
	t_fvector2	ray;
	t_fvector2	pos;
	int			i;

	pos = cub->player.pos;
	ray = pos;
	i = 0;
	while (cub->parse.map[(int)ray.y][(int)ray.x] != '1'
		&& cub->parse.map[(int)ray.y][(int)ray.x] != 'D'
		&& cub->parse.map[(int)ray.y][(int)ray.x] != 'O'
		&& cub->parse.map[(int)ray.y][(int)ray.x] != 'C')
	{
		if (ray_mm_border(pos, ray) == true)
			break ;
		put_pixel_to_img(&cub->img.display,
			(ray.x - pos.x) * TILE_SIZE + 210,
			(ray.y - pos.y) * TILE_SIZE + 110,
			RAY_COLOR);
		ray.x += cos(angle) * RAY_STEP;
		ray.y += sin(angle) * RAY_STEP;
		i++;
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
