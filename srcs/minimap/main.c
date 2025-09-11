/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:37:14 by wimam             #+#    #+#             */
/*   Updated: 2025/09/11 20:12:00 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	clear_old_map(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->img.mm_floor, 0, 0);
}

static void	draw_frame(t_cub *cub)
{
	draw_no_bg(cub, cub->img.mm_frame, 0, 0);
}

void	minimap(t_cub *cub)
{
	clear_old_map(cub);
	draw_walls(cub);
	draw_frame(cub);
}
