/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 10:39:49 by wimam             #+#    #+#             */
/*   Updated: 2025/10/28 20:11:29 by mohmajdo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

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
	cub->textures[5] = load_tex_animation(cub->img.demon);
	render_floor_ceiling(cub);
	angle2vector(&cub->player);
	wall_cast(cub);
	render_sprites(cub);
}
