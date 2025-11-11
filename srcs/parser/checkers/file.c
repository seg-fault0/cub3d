/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:00:54 by wimam             #+#    #+#             */
/*   Updated: 2025/11/11 14:07:53 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	check_file(char **file)
{
	int	y;
	int	map_i;

	y = -1;
	map_i = get_map_i(file);
	while (file[++y])
	{
		if (ft_memcmp(file[y], "NO", 2) == 0
			|| ft_memcmp(file[y], "SO", 2) == 0
			|| ft_memcmp(file[y], "WE", 2) == 0
			|| ft_memcmp(file[y], "EA", 2) == 0
			|| ft_memcmp(file[y], "F", 1) == 0
			|| ft_memcmp(file[y], "C", 1) == 0
			|| file[y][0] == '\n')
			continue ;
		else if (y == map_i)
			return (true);
		else
			return (false);
	}
	return (true);
}
