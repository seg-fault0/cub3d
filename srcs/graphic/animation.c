/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:33:08 by wimam             #+#    #+#             */
/*   Updated: 2025/10/12 16:06:01 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	mlx_xpm_animaton(void *mlx, t_img demon[DEMON_NBR])
{
	int	i;

	mlx_xpm(mlx, "./textures/demon/1.xpm", &demon[0]);
	mlx_xpm(mlx, "./textures/demon/2.xpm", &demon[1]);
	mlx_xpm(mlx, "./textures/demon/3.xpm", &demon[2]);
	mlx_xpm(mlx, "./textures/demon/4.xpm", &demon[3]);
	mlx_xpm(mlx, "./textures/demon/5.xpm", &demon[4]);
	mlx_xpm(mlx, "./textures/demon/6.xpm", &demon[5]);
	mlx_xpm(mlx, "./textures/demon/7.xpm", &demon[6]);
	i = -1;
	while(++i < DEMON_NBR)
	{
		if (!demon[i].img)
		{
			if (i != 0)
				mlx_destroy_image(mlx, demon[0].img);
			demon[0].img = NULL;
			break;
		}
	}
}