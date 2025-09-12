/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 08:40:04 by wimam             #+#    #+#             */
/*   Updated: 2025/09/12 11:34:19 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	if (cub->parse.map[(int) new_y][(int) new_x] == '1')
		return (true);
	return (false);
}
