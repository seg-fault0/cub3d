/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:55:32 by wimam             #+#    #+#             */
/*   Updated: 2025/09/12 07:39:11 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_player(t_cub *cub)
{
	mlx_draw(cub, PLAYER, 0, 0);
}

void	player_draw(t_cub *cub)
{
	draw_player(cub);
}
