/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:39:49 by wimam             #+#    #+#             */
/*   Updated: 2025/10/12 11:03:01 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	render_floor_ceiling(t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				put_pixel_to_img(&cub->img.display, x, y, cub->clr.sky);
			else
				put_pixel_to_img(&cub->img.display, x, y, cub->clr.floor);
		}
	}
}


void	render_world(t_cub *cub)
{
	render_floor_ceiling(cub);
	world_raycaster(cub);
}
