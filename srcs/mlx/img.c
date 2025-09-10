/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:42:09 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 11:33:58 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	imgs_bzero(t_imgs *imgs)
{
	ft_memset(&imgs->mm_frame, 0, sizeof(t_img));
}

void	free_img(t_cub *cub)
{
	if (cub->img.mm_frame.p)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_frame.p);
}

void	*mlx_get_img(void *mlx, char *path, int *width, int *height)
{
	int	size;

	return (mlx_xpm_file_to_image(mlx, path, width, height));
}

bool	img_init(t_cub *cub)
{
	cub->img.mm_frame.p = mlx_get_img(cub->mlx.mlx, MM_FRAME, &cub->img.mm_frame.width, &cub->img.mm_frame.height);
	if (!cub->img.mm_frame.p)
		return (err_msg(ERR_IMG), free_img(cub), false);
	return (true);
}
