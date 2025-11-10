/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:09:48 by wimam             #+#    #+#             */
/*   Updated: 2025/11/10 18:25:14 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_max_len(char **map)
{
	int	max_len;
	int	i;

	max_len = 0;
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > max_len)
			max_len = ft_strlen(map[i]);
	}
	return (max_len);
}

char	**same_len(char **map)
{
	int		max_len;
	int		i;
	char	*tmp;

	max_len = get_max_len(map);
	i = -1;
	while (map[++i])
	{
		tmp = map[i];
		map[i] = ft_calloc(max_len + 1, sizeof(char));
		if (!map[i])
		{
			map[i] = tmp;
			free2(map);
			return (NULL);
		}
		ft_memmove(map[i], tmp, ft_strlen(tmp));
		free(tmp);
	}
	return (map);
}
