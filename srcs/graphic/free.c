/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:30:08 by wimam             #+#    #+#             */
/*   Updated: 2025/10/13 12:06:02 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	imgs_bzero(t_imgs *imgs)
{
	ft_memset(&imgs->display, 0, sizeof(t_img));
	ft_memset(&imgs->mm_frame, 0, sizeof(t_img));
	ft_memset(&imgs->mm_wall, 0, sizeof(t_img));
	ft_memset(&imgs->mm_floor, 0, sizeof(t_img));
	ft_memset(&imgs->mm_demon, 0, sizeof(t_img));
	ft_memset(&imgs->n_wall, 0, sizeof(t_img));
	ft_memset(&imgs->s_wall, 0, sizeof(t_img));
	ft_memset(&imgs->e_wall, 0, sizeof(t_img));
	ft_memset(&imgs->w_wall, 0, sizeof(t_img));
	ft_memset(&imgs->player, 0, sizeof(t_img));
	ft_memset(&imgs->demon, 0, sizeof(t_img) * DEMON_NBR);
	ft_memset(imgs, 0, sizeof(imgs));
}

void	free_img(t_cub *cub)
{
	if (cub->img.mm_frame.img)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_frame.img);
	if (cub->img.mm_wall.img)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_wall.img);
	if (cub->img.mm_floor.img)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_floor.img);
	if (cub->img.n_wall.img)
		mlx_destroy_image(cub->mlx.mlx, cub->img.n_wall.img);
	if (cub->img.s_wall.img)
		mlx_destroy_image(cub->mlx.mlx, cub->img.s_wall.img);
	if (cub->img.e_wall.img)
		mlx_destroy_image(cub->mlx.mlx, cub->img.e_wall.img);
	if (cub->img.w_wall.img)
		mlx_destroy_image(cub->mlx.mlx, cub->img.w_wall.img);
	if (cub->img.display.img)
		mlx_destroy_image(cub->mlx.mlx, cub->img.display.img);
	if (cub->img.mm_demon.img)
		mlx_destroy_image(cub->mlx.mlx, cub->img.mm_demon.img);
	if (cub->img.player.img)
		mlx_destroy_image(cub->mlx.mlx, cub->img.player.img);
}

void	free_animation(void *mlx, t_img demon[DEMON_NBR])
{
	int	i;

	i = -1;
	while (++i < DEMON_NBR)
	{
		if (demon[i].img)
			mlx_destroy_image(mlx, demon[i].img);
	}
}
