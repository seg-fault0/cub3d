/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:55:32 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 20:11:08 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_player(t_cub *cub)
{
	int	x;
	int	y;

	x = ((WIN_WIDTH - cub->img.player.width) / 2);
	y = WIN_HEIGHT - cub->img.player.height;
	draw_no_bg(cub, cub->img.player, x, y);
}

void	player_draw(t_cub *cub)
{
	draw_player(cub);
}
