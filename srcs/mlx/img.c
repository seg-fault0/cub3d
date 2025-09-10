/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:42:09 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 10:17:32 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_img(t_cub *cub)
{
	if (cub->img.mm_frame)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_frame);
}

void	*mlx_get_img(void *mlx, char *path)
{
	int	size;

	return (mlx_xpm_file_to_image(mlx, path, &size, &size));
}

bool	img_init(t_cub *cub)
{
	int		size;

	cub->img.mm_frame = mlx_get_img(cub->mlx.mlx, MM_FRAME);
	if (!cub->img.mm_frame)
		return (err_msg(ERR_IMG), free_img(cub), false);
	return (true);
}
