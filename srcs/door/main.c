/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:51:20 by wimam             #+#    #+#             */
/*   Updated: 2025/10/13 13:44:31 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	door(t_cub *cub)
{
	static unsigned int	speed;
	char				**map;
	int					y;
	int					x;

	if (speed == UINT_MAX)
		speed = 0;
	if ((speed % DOOR_SPEED) == 0)
	{
		map = cub->parse.map;
		y = -1;
		while (map[++y])
		{
			x = -1;
			while (map[y][++x] != '\n')
			{
				if (map[y][x] == 'C')
					map[y][x] = 'O';
				else if (map[y][x] == 'O')
					map[y][x] = 'C';
			}
		}
		print_arr(map);
	}
	speed++;
}
