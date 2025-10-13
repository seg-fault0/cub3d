/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 04:12:52 by wimam             #+#    #+#             */
/*   Updated: 2025/10/13 15:23:21 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define UPDATE_RATE 500

static void	diplay_frame(t_cub *cub)
{
	render_world(cub);
	minimap(cub);
	player(cub);
	door(cub);
	mlx_put_image_to_window(cub->mlx.mlx,
		cub->mlx.win, cub->img.display.img, 0, 0);
}

int	game_cycle(t_cub *cub)
{
	static unsigned int	fps;

	if (fps == UINT_MAX)
		fps = 0;
	if ((fps % UPDATE_RATE) == 0)
	{
		if (cub->key.esq == true)
			ft_exit(cub, 0);
		diplay_frame(cub);
	}
	return (fps++, 0);
}
