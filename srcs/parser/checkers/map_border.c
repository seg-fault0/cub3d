/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 09:06:50 by wimam             #+#    #+#             */
/*   Updated: 2025/10/13 12:43:37 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	cur_line(char *prev_line, char *line, char *next_line)
{
	int		i;
	bool	zero_found;

	i = 0;
	zero_found = false;
	while (line[i])
	{
		if (line[i] == '0')
			zero_found = true;
		else
			zero_found = false;
		if (zero_found == true)
		{
			if (allowed_char(line[i]) == false
				|| allowed_char(next_line[i]) == false
				|| allowed_char(prev_line[i]) == false)
				return (false);
		}
		i++;
	}
	return (true);
}

static bool	first_last_line(char **map, int max)
{
	int	i;

	i = 0;
	while (map[0] && map[0][i] != '\n')
	{
		if (map[0][i] != ' ' && map[0][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (map[max] && map[max][i] != '\n')
	{
		if (map[max][i] != ' ' && map[max][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_map_border(t_cub *cub)
{
	int		y;
	char	**map;

	map = cub->parse.map;
	if (!map)
		return (false);
	if (first_last_line(map, cub->parse.max_map_y - 1) == false)
		return (err_msg(ERR_MAP_BORDER), false);
	y = 1;
	while (y < cub->parse.max_map_y - 1)
	{
		if (cur_line(map[y - 1], map[y], map[y + 1]) == false)
			return (err_msg(ERR_MAP_BORDER), false);
		y++;
	}
	return (true);
}
