/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:06:26 by wimam             #+#    #+#             */
/*   Updated: 2025/09/11 19:53:30 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define TILE_SIZE 20
#define RADIUS 20

void	draw_walls(t_cub *cub)
{
	int	x;
	int	y;
	int	map_x;
	int	map_y;

	y = -1;
	mlx_clear_window(cub->mlx.mlx, cub->mlx.win);
	while (++y < RADIUS - 10)
	{
		x = -1;
		while (++x < RADIUS)
		{
			map_x = cub->player.xp + x;
			map_y = cub->player.yp + y;
			if (map_y >= 0 && map_y < cub->parse.max_map_y
				&& map_x >= 0 && map_x < 20)
			{
				if (cub->parse.map[map_y][map_x] == '1')
					mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->img.mm_wall, x * TILE_SIZE, y * TILE_SIZE);
			}
		}
	}
}
