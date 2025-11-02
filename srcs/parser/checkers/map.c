/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:14:18 by wimam             #+#    #+#             */
/*   Updated: 2025/11/02 15:19:47 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	check_map_extension(char *path)
{
	int		len;
	int		max;
	int		i;

	if (!path)
		return (false);
	len = ft_strlen(path);
	if (len < 4)
		return (false);
	max = len - 4;
	i = 0;
	while (max + i < len)
	{
		if (path[max + i] != MAP_EXTENTION[i])
			return (false);
		i++;
	}
	return (true);
}
