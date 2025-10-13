/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:10:05 by wimam             #+#    #+#             */
/*   Updated: 2025/10/13 11:53:44 by wimam            ###   ########.fr       */
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
		return (0.001);
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
				cub->player.pos.x = x;
				cub->player.pos.y = y;
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
