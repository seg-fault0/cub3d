/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:28:59 by wimam             #+#    #+#             */
/*   Updated: 2025/11/01 17:37:19 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	found_player(char c)
{
	if (c == 'E' || c == 'W' || c == 'N' || c == 'S')
		return (true);
	return (false);
}

bool	check_double_player(t_cub *cub)
{
	int		player_found;
	int		y;
	int		x;

	player_found = 0;
	y = -1;
	while (cub->parse.map[++y])
	{
		x = -1;
		while (cub->parse.map[y][++x])
		{
			if (found_player(cub->parse.map[y][x]) == true)
				player_found++;
			if (player_found > 1)
				return (err_msg(ERR_MLTPL_PLYR), false);
		}
	}
	if (player_found == 0)
		return (err_msg(ERR_PLYR_NF), false);
	return (true);
}
