/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 08:33:12 by wimam             #+#    #+#             */
/*   Updated: 2025/10/11 01:16:38 by mohmajdo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void update_vectors_from_angle(t_player *player)
{
	player->dir_x = cos(player->angle);
	player->dir_y = sin(player->angle);
	player->plane_x = -sin(player->angle) * 0.66;
	player->plane_y = cos(player->angle) * 0.66;
}

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
	{
		cub->player.angle += ROTATION_SPEED;
		update_vectors_from_angle(&cub->player);
	}
	if (cub->key.l_arr == true)
	{
		cub->player.angle -= ROTATION_SPEED;
		update_vectors_from_angle(&cub->player);
	}
}

