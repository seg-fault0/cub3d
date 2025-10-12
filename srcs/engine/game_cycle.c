/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 04:12:52 by wimam             #+#    #+#             */
/*   Updated: 2025/10/12 17:00:02 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define UPDATE_RATE 500

int	game_cycle(t_cub *cub)
{
	static unsigned int	fps;

	if (fps == UINT_MAX)
		fps = 0;
	if ((fps % UPDATE_RATE) == 0)
	{
		render_world(cub);
		minimap(cub);
		player(cub);
		mlx_put_image_to_window(cub->mlx.mlx,
			cub->mlx.win, cub->img.display.img, 0, 0);
	}
	return (fps++, 0);
}
