/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:55:32 by wimam             #+#    #+#             */
/*   Updated: 2025/10/13 12:35:23 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_player(t_cub *cub)
{
	int	x;
	int	y;

	x = (WIN_WIDTH / 2) - (cub->img.player.width / 2);
	y = WIN_HEIGHT - cub->img.player.height;
	draw_img_to_img(&cub->img.display, &cub->img.player,
		x, y);
}

void	player(t_cub *cub)
{
	if (collisions(cub) == false)
		player_mouvement(cub);
	draw_player(cub);
}
