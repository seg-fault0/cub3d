/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spirites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:55:14 by wimam             #+#    #+#             */
/*   Updated: 2025/10/25 17:07:26 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	count_sprites(t_cub *cub)
{
	int	i;
	int	j;
	int	sprite_count;

	sprite_count = 0;
	i = -1;
	while (++i < cub->parse.max_map_y)
	{
		j = -1;
		while (cub->parse.map[i][++j])
		{
			if (cub->parse.map[i][j] == 'D')
				sprite_count++;
		}
	}
	cub->sprites.count = sprite_count;
	cub->sprites.sprites = malloc(sizeof(t_sprite) * sprite_count);
	cub->sprites.zbuffer = malloc(sizeof(double) * WIN_WIDTH);
	cub->sprites.order = malloc(sizeof(int) * sprite_count);
	cub->sprites.distance = malloc(sizeof(double) * sprite_count);
	if (!cub->sprites.sprites || !cub->sprites.zbuffer
		|| !cub->sprites.order || !cub->sprites.distance)
		return (false);
	return (true);
}

bool	init_sprite_system(t_cub *cub)
{
	int	i;
	int	j;
	int	idx;

	if (count_sprites(cub) == false)
		return (false);
	idx = 0;
	i = -1;
	while (++i < cub->parse.max_map_y)
	{
		j = -1;
		while (cub->parse.map[i][++j])
		{
			if (cub->parse.map[i][j] == 'D')
			{
				cub->sprites.sprites[idx].pos.x = j + 0.5;
				cub->sprites.sprites[idx].pos.y = i + 0.5;
				cub->sprites.sprites[idx].texture = 5;
				cub->sprites.sprites[idx].type = 2;
				idx++;
			}
		}
	}
	return (true);
}

static void	spirite_ordre(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < cub->sprites.count)
	{
		cub->sprites.order[i] = i;
		cub->sprites.distance[i] = ((cub->player.pos.x
					- cub->sprites.sprites[i].pos.x) * (cub->player.pos.x
					- cub->sprites.sprites[i].pos.x) + (cub->player.pos.y
					- cub->sprites.sprites[i].pos.y) * (cub->player.pos.y
					- cub->sprites.sprites[i].pos.y));
	}
}

void	sort_sprites(t_cub *cub)
{
	int		i;
	int		j;
	int		temp_order;
	double	temp_dist;

	spirite_ordre(cub);
	i = -1;
	while (++i < cub->sprites.count - 1)
	{
		j = -1;
		while (++j < cub->sprites.count - 1 - i)
		{
			if (cub->sprites.distance[cub->sprites.order[j]]
				< cub->sprites.distance[cub->sprites.order[j + 1]])
			{
				temp_order = cub->sprites.order[j];
				temp_dist = cub->sprites.distance[j];
				cub->sprites.order[j] = cub->sprites.order[j + 1];
				cub->sprites.distance[j] = cub->sprites.distance[j + 1];
				cub->sprites.order[j + 1] = temp_order;
				cub->sprites.distance[j + 1] = temp_dist;
			}
		}
	}
}
