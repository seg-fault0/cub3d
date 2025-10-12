/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 08:40:04 by wimam             #+#    #+#             */
/*   Updated: 2025/10/12 16:44:03 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	can_player_move(t_cub *cub, float y, float x)
{
	float	diff_x;
	float	diff_y;

	diff_x = x - (int)x;
	diff_y = y - (int)y;
	if (diff_x > 0 && x > cub->player.pos.x)
		x += 1;
	if (diff_y > 0 && y > cub->player.pos.y)
		y += 1;
	if (cub->parse.map[(int)y][(int)x] == '1'
		|| cub->parse.map[(int)y][(int)x] == 'D')
		return (true);
	return (false);
}

bool	collisions(t_cub *cub)
{
	float	new_x;
	float	new_y;

	new_x = cub->player.pos.x;
	new_y = cub->player.pos.y;
	if (cub->key.w)
	{
		new_x += cos(cub->player.angle) * PLAYER_SPEED;
		new_y += sin(cub->player.angle) * PLAYER_SPEED;
	}
	if (cub->key.s)
	{
		new_x -= cos(cub->player.angle) * PLAYER_SPEED;
		new_y -= sin(cub->player.angle) * PLAYER_SPEED;
	}
	if (cub->key.a)
	{
		new_x += cos(cub->player.angle - M_PI / 2) * PLAYER_SPEED;
		new_y += sin(cub->player.angle - M_PI / 2) * PLAYER_SPEED;
	}
	if (cub->key.d)
	{
		new_x += cos(cub->player.angle + M_PI / 2) * PLAYER_SPEED;
		new_y += sin(cub->player.angle + M_PI / 2) * PLAYER_SPEED;
	}
	return (can_player_move(cub, new_y, new_x));
}
