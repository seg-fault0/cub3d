/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 09:30:36 by wimam             #+#    #+#             */
/*   Updated: 2025/09/13 10:22:33 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_cur_i(char **file)
{
	int	i;
	int	last;

	i = -1;
	last = 0;
	while (file[++i])
	{
		if (ft_memcmp(file[i], "NO", 2) == 0
			|| ft_memcmp(file[i], "SO", 2) == 0
			|| ft_memcmp(file[i], "WE", 2) == 0
			|| ft_memcmp(file[i], "EA", 2) == 0
			|| ft_memcmp(file[i], "F", 1) == 0
			|| ft_memcmp(file[i], "C", 1) == 0
			|| file[i][0] == '\n')
			last = i;
	}
	i = last + 1;
	while (file[i] && file[i][0] == '\0')
		i++;
	return (i);
}

bool	get_map(t_cub *cub)
{
	int	cur_i;

	cur_i = get_cur_i(cub->parse.file);
	cub->parse.map = get_2darr_cp(&cub->parse.file[cur_i]);
	return (true);
}
