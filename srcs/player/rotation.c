/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:08:43 by wimam             #+#    #+#             */
/*   Updated: 2025/10/13 15:08:59 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	player_rotation(t_cub *cub)
{
	if (cub->key.r_arr == true)
		cub->player.angle += ROTATION_SPEED;
	if (cub->key.l_arr == true)
		cub->player.angle -= ROTATION_SPEED;
}