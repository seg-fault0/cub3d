/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 08:33:12 by wimam             #+#    #+#             */
/*   Updated: 2025/09/13 08:49:12 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	player_mouvement(t_cub *cub)
{
	if (cub->key.esq == true)
		ft_exit(cub, 0);
	if (cub->key.w == true)
	{
		cub->player.xp += cos(cub->player.angle) * PLAYER_SPEED;
		cub->player.yp += sin(cub->player.angle) * PLAYER_SPEED;
	}
	if (cub->key.s == true)
	{
		cub->player.xp -= cos(cub->player.angle) * PLAYER_SPEED;
		cub->player.yp -= sin(cub->player.angle) * PLAYER_SPEED;
	}
	if (cub->key.a == true)
	{
		cub->player.xp += cos(cub->player.angle - M_PI / 2) * PLAYER_SPEED;
		cub->player.yp += sin(cub->player.angle - M_PI / 2) * PLAYER_SPEED;
	}
	if (cub->key.d == true)
	{
		cub->player.xp += cos(cub->player.angle + M_PI / 2) * PLAYER_SPEED;
		cub->player.yp += sin(cub->player.angle + M_PI / 2) * PLAYER_SPEED;
	}
	if (cub->key.r_arr == true)
		cub->player.angle += ROTATION_SPEED;
	if (cub->key.l_arr == true)
		cub->player.angle -= ROTATION_SPEED;
}
