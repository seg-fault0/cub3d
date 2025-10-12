/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:06:26 by wimam             #+#    #+#             */
/*   Updated: 2025/10/12 10:41:36 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define X_RADIUS 20
#define Y_RADIUS 10
#define IMG_SIZE 20

static void	draw_minimap_cp(t_cub *cub, char **map)
{
	int		y;
	int		x;
	float	diff_y;
	float	diff_x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			diff_x = cub->player.xp - (int)cub->player.xp;
			diff_y = cub->player.yp - (int)cub->player.yp;
			if (map[y][x] == '1')
				draw_img_to_img(&cub->img.display, &cub->img.mm_wall,(x - diff_x) * IMG_SIZE, (y - diff_y) * IMG_SIZE);
		}
	}
}

static char	**get_minimap_cp(t_cub *cub)
{
	char	**minimap;
	int		y;
	int		x;
	int		map_y;
	int		map_x;

	minimap = malloc((Y_RADIUS + 1) * sizeof(char *));
	y = -1;
	while (++y < Y_RADIUS)
	{
		minimap[y] = malloc(X_RADIUS + 1);
		ft_memset(minimap[y], '0', X_RADIUS);
		x = -1;
		while (++x < X_RADIUS)
		{
			map_y = (int)cub->player.yp - Y_RADIUS / 2 + y;
			map_x = (int)cub->player.xp - X_RADIUS / 2 + x;
			if (map_y >= 0 && map_y < cub->parse.max_map_y
				&& map_x >= 0 && map_x < (int)ft_strlen(cub->parse.map[map_y]))
				minimap[y][x] = cub->parse.map[map_y][map_x];
		}
		minimap[y][X_RADIUS] = '\0';
	}
	minimap[Y_RADIUS] = NULL;
	return (minimap);
}

void	draw_walls(t_cub *cub)
{
	char	**map_cp;

	map_cp = get_minimap_cp(cub);
	draw_minimap_cp(cub, map_cp);
	free2(map_cp);
}
