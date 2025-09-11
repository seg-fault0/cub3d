/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:42:09 by wimam             #+#    #+#             */
/*   Updated: 2025/09/11 19:18:05 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	imgs_bzero(t_imgs *imgs)
{
	ft_memset(&imgs->mm_frame, 0, sizeof(t_img));
	ft_memset(&imgs->player, 0, sizeof(t_img));
	ft_memset(imgs, 0, sizeof(imgs));
}

void	free_img(t_cub *cub)
{
	if (cub->img.mm_frame.p)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_frame.p);
	if (cub->img.player.p)
		mlx_destroy_image(cub->mlx.mlx, cub->img.player.p);
	if (cub->img.mm_wall)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_wall);
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
	cub->img.player.p = mlx_get_img(cub->mlx.mlx, PLAYER, &cub->img.player.width, &cub->img.player.height);
	cub->img.mm_wall = mlx_xpm_file_to_image(cub->mlx.mlx, MM_WALL, &size, &size);
	if (!cub->img.mm_frame.p || !cub->img.player.p || !cub->img.mm_wall)
		return (err_msg(ERR_IMG), false);
	return (true);
}
