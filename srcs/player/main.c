/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:55:32 by wimam             #+#    #+#             */
/*   Updated: 2025/09/11 19:52:15 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_player(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->img.player, (WIN_WIDTH / 2) - 400, WIN_HEIGHT - 513);
}

void	player_draw(t_cub *cub)
{
	draw_player(cub);
}
