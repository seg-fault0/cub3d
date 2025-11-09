/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:06:50 by wimam             #+#    #+#             */
/*   Updated: 2025/11/09 14:12:48 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	check_one_norm(char **map, t_ivector2 it)
{
	if (map[it.y + 1] && map[it.y + 1][it.x + 1]
		&& map[it.y + 1][it.x + 1] != '\n'
		&& allowed_char(map[it.y + 1][it.x + 1]) == true)
		return (true);
	if (it.x > 0 && it.y > 0
		&& allowed_char(map[it.y - 1][it.x - 1]) == true)
		return (true);
	if (it.x > 0 && map[it.y + 1] && map[it.y + 1][it.x]
		&& map[it.y + 1][it.x] != '\n'
		&& allowed_char(map[it.y + 1][it.x - 1]) == true)
		return (true);
	if (it.y > 0 && map[it.y - 1][it.x + 1]
		&& map[it.y - 1][it.x + 1] != '\n'
		&& allowed_char(map[it.y - 1][it.x + 1]) == true)
		return (true);
	return (false);
}

bool	check_one(char **map, t_ivector2 it)
{
	if (it.x > 0 && allowed_char(map[it.y][it.x - 1]) == true)
		return (true);
	if (it.y > 0 && allowed_char(map[it.y - 1][it.x]) == true)
		return (true);
	if (map[it.y + 1] && map[it.y + 1][it.x]
		&& map[it.y + 1][it.x] != '\n'
		&& allowed_char(map[it.y + 1][it.x]) == true)
		return (true);
	if (map[it.y][it.x + 1] && map[it.y][it.x + 1] != '\n'
		&& allowed_char(map[it.y][it.x + 1]) == true)
		return (true);
	return (check_one_norm(map, it));
}

bool	check_other(char **map, t_ivector2 it)
{
	if (it.x > 0 && allowed_char(map[it.y][it.x - 1]) == false)
		return (false);
	if (it.y > 0 && allowed_char(map[it.y - 1][it.x]) == false)
		return (false);
	if (map[it.y + 1] && map[it.y + 1][it.x]
		&& map[it.y + 1][it.x] != '\0'
		&& allowed_char(map[it.y + 1][it.x]) == false)
		return (false);
	if (map[it.y][it.x + 1] && map[it.y][it.x + 1] != '\0'
		&& allowed_char(map[it.y][it.x + 1]) == false)
		return (false);
	return (true);
}

bool	check_map_border(t_cub *cub)
{
	t_ivector2	it;
	char		**map;

	map = cub->parse.map;
	it.y = -1;
	if (!map || !map[0] || !map[1])
		return (err_msg(ERR_BAD_MAP), false);
	while (map[++it.y])
	{
		it.x = -1;
		while (map[it.y][++it.x] && map[it.y][it.x] != '\n')
		{
			if (map[it.y][it.x] == '1')
			{
				if (check_one(map, it) == false)
					return (err_msg(ERR_BAD_MAP), false);
			}
			else if (allowed_char(map[it.y][it.x]) == true)
			{
				if (check_other(map, it) == false)
					return (err_msg(ERR_BAD_MAP), false);
			}
			else if (map[it.y][it.x] != ' ')
				return (err_msg(ERR_BAD_MAP), false);
		}
	}
	return (true);
}
