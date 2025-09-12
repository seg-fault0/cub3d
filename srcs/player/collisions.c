/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 08:40:04 by wimam             #+#    #+#             */
/*   Updated: 2025/09/12 12:01:05 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	can_player_move(t_cub *cub, float y, float x)
{
	float	diff_x;
	float	diff_y;

	diff_x = x - (int)x;
	diff_y = y - (int)y;
	if (diff_x > 0 && x > cub->player.xp)
		x += 1;
	if (diff_y > 0 && y > cub->player.yp)
		y += 1;
	if (cub->parse.map[(int)y][(int)x] == '1')
		return (true);
	return (false);
}

bool	collisions(t_cub *cub)
{
	float	new_x;
	float	new_y;

	new_x = cub->player.xp;
	new_y = cub->player.yp;
	if (cub->key.w == true)
		new_y -= PLAYER_SPEED;
	if (cub->key.s == true)
		new_y += PLAYER_SPEED;
	if (cub->key.a == true)
		new_x -= PLAYER_SPEED;
	if (cub->key.d == true)
		new_x += PLAYER_SPEED;
	return (can_player_move(cub, new_y, new_x));
}
