/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:10:05 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 20:34:31 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	pos_init(t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 10)
	{
		x = 0;
		while (cub->map[y][++x] != '\n')
		{
			if (cub->map[y][x] == 'P')
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
	return (true);
}
