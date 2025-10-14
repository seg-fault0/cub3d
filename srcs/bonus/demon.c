/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:18:53 by wimam             #+#    #+#             */
/*   Updated: 2025/10/14 20:40:59 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	demon_counter(char **map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'D')
				count++;
		}
	}
	return (count);
}

static void	get_demons_pos(t_demon *demon, char **map)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'D')
				demon->pos[i++] = (t_ivector2){x, y};
		}
	}
}

bool	demon_init(t_cub *cub)
{
	int	total;

	total = demon_counter(cub->parse.map);
	cub->demon.total = total;
	if (total == 0)
		return (true);
	cub->demon.pos = malloc (total * sizeof(t_ivector2));
	if (!cub->demon.pos)
		return (err_msg(ERR_MALLOC), false);
	get_demons_pos(&cub->demon, cub->parse.map);
	return (true);
}
