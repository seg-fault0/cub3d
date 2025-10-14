/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:51:20 by wimam             #+#    #+#             */
/*   Updated: 2025/10/14 13:40:32 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	reverse(char c)
{
	if (c == 'C')
		return ('O');
	else if (c == 'O')
		return ('C');
	return (c);
}

void	door(t_cub *cub)
{
	static bool	pressed;
	char		**map;
	int			y;
	int			x;

	map = cub->parse.map;
	if (cub->key.e && !pressed)
	{
		pressed = true;
		y = -1;
		while (map[++y])
		{
			x = -1;
			while (map[y][++x] != '\n')
			{
				if (abs((int)cub->player.pos.x - x) < DOOR_RADIOUS
					&& abs((int)cub->player.pos.y - y) < DOOR_RADIOUS
					&& !((int)cub->player.pos.x == x
						&& (int)cub->player.pos.y == y))
					map[y][x] = reverse(map[y][x]);
			}
		}
	}
	else if (!cub->key.e)
		pressed = false;
}
