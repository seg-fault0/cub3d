/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:42:09 by wimam             #+#    #+#             */
/*   Updated: 2025/09/11 20:09:26 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	imgs_bzero(t_imgs *imgs)
{
	ft_memset(&imgs->mm_frame, 0, sizeof(t_img));
	ft_memset(imgs, 0, sizeof(imgs));
}

void	free_img(t_cub *cub)
{
	if (cub->img.mm_frame.p)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_frame.p);
	if (cub->img.player)
		mlx_destroy_image(cub->mlx.mlx, cub->img.player);
	if (cub->img.mm_wall)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_wall);
	if (cub->img.mm_floor)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_floor);
}

void	*mlx_get_img(void *mlx, char *path, int *width, int *height)
{
	int	size;

	return (mlx_xpm_file_to_image(mlx, path, width, height));
}

bool	img_init(t_cub *cub)
{
	int	size;

	cub->img.mm_frame.p = mlx_get_img(cub->mlx.mlx, MM_FRAME, &cub->img.mm_frame.width, &cub->img.mm_frame.height);
	cub->img.player = mlx_get_img(cub->mlx.mlx, PLAYER, &size, &size);
	cub->img.mm_wall = mlx_xpm_file_to_image(cub->mlx.mlx, MM_WALL, &size, &size);
	cub->img.mm_floor = mlx_xpm_file_to_image(cub->mlx.mlx, MM_FLOOR, &size, &size);
	if (!cub->img.mm_frame.p || !cub->img.player || !cub->img.mm_wall || !cub->img.mm_floor)
		return (err_msg(ERR_IMG), false);
	return (true);
}
