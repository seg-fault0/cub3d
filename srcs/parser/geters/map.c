/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 09:30:36 by wimam             #+#    #+#             */
/*   Updated: 2025/11/10 17:07:32 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	is_top_of_map(char *line)
{
	int		i;
	bool	one_found;

	one_found = false;
	i = -1;
	while (line[++i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		if (line[i] == '1')
			one_found = true;
	}
	if (one_found == true)
		return (true);
	return (false);
}

static int	get_map_i(char **file)
{
	int	i;

	i = -1;
	while (file[++i])
	{
		if (is_top_of_map(file[i]) == true)
			return (i);
	}
	return (-1);
}

bool	get_map(t_cub *cub)
{
	int	map_i;

	map_i = get_map_i(cub->parse.file);
	if (map_i == -1)
		return (err_msg(ERR_MAP_NF), false);
	cub->parse.map = get_2darr_cp(&cub->parse.file[map_i]);
	if (!cub->parse.map)
		return (err_msg(ERR_LONG_LINE), false);
	cub->parse.max_map_y = get_arr_size(cub->parse.map);
	return (true);
}
