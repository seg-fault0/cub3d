/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 08:33:12 by wimam             #+#    #+#             */
/*   Updated: 2025/10/13 15:20:31 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	collision(t_cub *cub, float y, float x)
{
	t_fvector2	d;
	t_ivector2	map;

	d.y = -COLLISION_RADIUS;
	while (d.y <= COLLISION_RADIUS)
	{
		d.x = -COLLISION_RADIUS;
		while (d.x <= COLLISION_RADIUS)
		{
			map.x = (int)(x + d.x);
			map.y = (int)(y + d.y);
			if (cub->parse.map[map.y][map.x] == '1'
				|| cub->parse.map[map.y][map.x] == 'D'
				|| cub->parse.map[map.y][map.x] == 'C')
				return (false);
			d.x += COLLISION_RADIUS;
		}
		d.y += COLLISION_RADIUS;
	}
	return (true);
}

void	player_mouvement(t_cub *cub)
{
	t_fvector2	new;

	new = cub->player.pos;
	if (cub->key.w)
	{
		new.x += cos(cub->player.angle) * PLAYER_SPEED;
		new.y += sin(cub->player.angle) * PLAYER_SPEED;
	}
	if (cub->key.s)
	{
		new.x -= cos(cub->player.angle) * PLAYER_SPEED;
		new.y -= sin(cub->player.angle) * PLAYER_SPEED;
	}
	if (cub->key.a)
	{
		new.x += cos(cub->player.angle - M_PI / 2) * PLAYER_SPEED;
		new.y += sin(cub->player.angle - M_PI / 2) * PLAYER_SPEED;
	}
	if (cub->key.d)
	{
		new.x += cos(cub->player.angle + M_PI / 2) * PLAYER_SPEED;
		new.y += sin(cub->player.angle + M_PI / 2) * PLAYER_SPEED;
	}
	if (collision(cub, cub->player.pos.y, new.x))
		cub->player.pos.x = new.x;
	if (collision(cub, new.y, cub->player.pos.x))
		cub->player.pos.y = new.y;
}
