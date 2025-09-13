/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:42:09 by wimam             #+#    #+#             */
/*   Updated: 2025/09/13 11:49:27 by wimam            ###   ########.fr       */
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
	if (cub->img.mm_wall)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_wall);
	if (cub->img.mm_floor)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_floor);
	if (cub->img.n_wall)
		mlx_destroy_image(cub->mlx.mlx, cub->img.n_wall);
	if (cub->img.s_wall)
		mlx_destroy_image(cub->mlx.mlx, cub->img.s_wall);
	if (cub->img.e_wall)
		mlx_destroy_image(cub->mlx.mlx, cub->img.e_wall);
	if (cub->img.w_wall)
		mlx_destroy_image(cub->mlx.mlx, cub->img.w_wall);
}

void	*mlx_xpm(void *mlx, char *path, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx, path, width, height));
}

bool	img_init(t_cub *cub)
{
	void	*mlx;
	int		size;

	mlx = cub->mlx.mlx;
	cub->img.mm_frame.p = mlx_xpm(mlx, MM_FRAME_PATH, &cub->img.mm_frame.width, &cub->img.mm_frame.height);
	cub->img.mm_wall = mlx_xpm(mlx, MM_WALL_PATH, &size, &size);
	cub->img.mm_floor = mlx_xpm(mlx, MM_FLOOR_PATH, &size, &size);
	cub->img.n_wall = mlx_xpm(mlx, cub->parse.n_wall, &size, &size);
	cub->img.s_wall = mlx_xpm(mlx, cub->parse.s_wall, &size, &size);
	cub->img.e_wall = mlx_xpm(mlx, cub->parse.e_wall, &size, &size);
	cub->img.w_wall = mlx_xpm(mlx, cub->parse.w_wall, &size, &size);
	if (!cub->img.mm_frame.p || !cub->img.mm_wall || !cub->img.mm_floor
		|| !cub->img.n_wall || !cub->img.s_wall || !cub->img.e_wall
		|| !cub->img.w_wall)
		return (err_msg(ERR_IMG), false);
	return (true);
}
