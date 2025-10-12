/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:33:08 by wimam             #+#    #+#             */
/*   Updated: 2025/10/12 16:00:07 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	mlx_xpm_animaton(void *mlx, t_img demon[DEMON_NBR])
{
	int	i;

	demon[0].img = mlx_xpm_file_to_image(mlx, "./textures/demon/1.xpm", &demon[0].width, &demon[0].height);
	demon[1].img = mlx_xpm_file_to_image(mlx, "./textures/demon/2.xpm", &demon[0].width, &demon[0].height);
	demon[2].img = mlx_xpm_file_to_image(mlx, "./textures/demon/3.xpm", &demon[0].width, &demon[0].height);
	demon[3].img = mlx_xpm_file_to_image(mlx, "./textures/demon/4.xpm", &demon[0].width, &demon[0].height);
	demon[4].img = mlx_xpm_file_to_image(mlx, "./textures/demon/5.xpm", &demon[0].width, &demon[0].height);
	demon[5].img = mlx_xpm_file_to_image(mlx, "./textures/demon/6.xpm", &demon[0].width, &demon[0].height);
	demon[6].img = mlx_xpm_file_to_image(mlx, "./textures/demon/7.xpm", &demon[0].width, &demon[0].height);
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