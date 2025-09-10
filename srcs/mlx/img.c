/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:42:09 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 09:13:19 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define MM_PLAYER "./textures/minimap/player.xpm"

void	*mlx_get_img(void *mlx, char *path)
{
	int	size;

	return (mlx_xpm_file_to_image(mlx, path, &size, &size));
}

bool	img_init(t_cub *cub)
{
	t_img	img;
	int		size;

	img = cub->img;
	img.mm_player = mlx_get_img(cub->mlx.mlx, MM_PLAYER);
	if (!img.mm_player)
		return (err_msg(ERR_IMG), free_img(cub), false);
	return (true);
}
