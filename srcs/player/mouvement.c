/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 08:33:12 by wimam             #+#    #+#             */
/*   Updated: 2025/09/12 11:31:50 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	player_mouvement(t_cub *cub)
{
	if (cub->key.esq == true)
		ft_exit(cub, 0);
	if (cub->key.w == true)
		cub->player.yp -= PLAYER_SPEED;
	if (cub->key.s == true)
		cub->player.yp += PLAYER_SPEED;
	if (cub->key.a == true)
		cub->player.xp -= PLAYER_SPEED;
	if (cub->key.d == true)
		cub->player.xp += PLAYER_SPEED;
	if (cub->key.d == true || cub->key.a == true || cub->key.s == true || cub->key.w == true)
		printf("yp = %f | xp = %f\n", cub->player.yp, cub->player.xp);
}
