/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:10:05 by wimam             #+#    #+#             */
/*   Updated: 2025/09/12 12:46:40 by wimam            ###   ########.fr       */
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
				cub->player.xp = x;
				cub->player.yp = y;
				break ;
			}
		}
	}
}

bool	player_init(t_cub *cub)
{
	pos_init(cub);
	cub->player.angle = 3 * M_PI / 2;
	return (true);
}
