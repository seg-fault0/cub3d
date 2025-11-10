/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:10:05 by wimam             #+#    #+#             */
/*   Updated: 2025/11/10 15:24:27 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static double	player_dir(char c)
{
	if (c == 'N')
		return (3 * M_PI / 2);
	else if (c == 'S')
		return (M_PI / 2);
	else if (c == 'E')
		return (2 * M_PI);
	else if (c == 'W')
		return (M_PI);
	return (-1);
}

static void	pos_angle_init(t_cub *cub)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	while (++y < cub->parse.max_map_y)
	{
		x = 0;
		while (cub->parse.map[y][++x] != '\n')
		{
			c = cub->parse.map[y][x];
			if (player_dir(c) > 0)
			{
				cub->player.pos.x = x + 0.5;
				cub->player.pos.y = y + 0.5;
				cub->player.angle = player_dir(c);
				break ;
			}
		}
	}
}

bool	player_init(t_cub *cub)
{
	pos_angle_init(cub);
	angle2vector(&cub->player);
	return (true);
}
