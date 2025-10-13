/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 21:06:26 by wimam             #+#    #+#             */
/*   Updated: 2025/10/13 15:50:48 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define X_RADIUS 20
#define Y_RADIUS 10

#define IMG_SIZE 20
#define D 0.5

static void	draw_minimap_cp(t_cub *cub, char **map)
{
	t_ivector2	it;
	t_fvector2	diff;

	it.y = 0;
	while (map[++it.y])
	{
		it.x = 0;
		while (map[it.y][++it.x])
		{
			diff.x = cub->player.pos.x - (int)cub->player.pos.x;
			diff.y = cub->player.pos.y - (int)cub->player.pos.y;
			if (map[it.y][it.x] == '1')
				draw_img_to_img(&cub->img.display, &cub->img.mm_wall,
					(it.x - diff.x + D) * IMG_SIZE, (it.y - diff.y + D) * IMG_SIZE);
			else if (map[it.y][it.x] == 'D')
				draw_img_to_img(&cub->img.display, &cub->img.mm_demon,
					(it.x - diff.x + D) * IMG_SIZE, (it.y - diff.y + D) * IMG_SIZE);
			else if (map[it.y][it.x] == 'O' || map[it.y][it.x] == 'C')
				draw_img_to_img(&cub->img.display, &cub->img.mm_door,
					(it.x - diff.x + D) * IMG_SIZE, (it.y - diff.y + D) * IMG_SIZE);
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
			map_y = (int)cub->player.pos.y - Y_RADIUS / 2 + y;
			map_x = (int)cub->player.pos.x - X_RADIUS / 2 + x;
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
