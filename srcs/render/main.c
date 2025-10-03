/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:39:49 by wimam             #+#    #+#             */
/*   Updated: 2025/09/15 23:51:28 by mohmajdo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define MM_HEIGHT 210
#define MM_WIDTH 400

// static void	render_floor_ceiling(t_cub *cub)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (++y < WIN_HEIGHT)
// 	{
// 		x = -1;
// 		while (++x < WIN_WIDTH)
// 		{
// 			if (x < MM_WIDTH && y < MM_HEIGHT)
// 				continue ;
// 			if (y < WIN_HEIGHT / 2)
// 				mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, x, y, cub->clr.sky);
// 			else
// 				mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, x, y, cub->clr.floor);
// 		}
// 	}
// }

void init_image(t_cub *cub)
{
    cub->img.img = mlx_new_image(cub->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
    cub->img.addr = mlx_get_data_addr(cub->img.img, 
                                       &cub->img.bits_per_pixel,
                                       &cub->img.size_line,
                                       &cub->img.endian);
}

void	render_world(t_cub *cub)
{
	// render_floor_ceiling(cub);
	world_raycaster(cub);
}
