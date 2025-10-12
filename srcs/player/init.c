/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:10:05 by wimam             #+#    #+#             */
/*   Updated: 2025/10/12 11:58:12 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	pos_init(t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < cub->parse.max_map_y)
	{
		x = 0;
		while (cub->parse.map[y][++x] != '\n')
		{
			if (cub->parse.map[y][x] == 'P')
			{
				cub->player.pos.x = x;
				cub->player.pos.y = y;
				break ;
			}
		}
	}
}

bool	player_init(t_cub *cub)
{
	pos_init(cub);
	cub->player.angle = 3 * M_PI / 2;
	cub->player.dir_x = 0;
	cub->player.dir_y = -1;
	cub->player.plane_x = 0.66;
	cub->player.plane_y = 0;
	return (true);
}
