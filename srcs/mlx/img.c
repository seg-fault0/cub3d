/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:42:09 by wimam             #+#    #+#             */
/*   Updated: 2025/10/12 15:24:45 by wimam            ###   ########.fr       */
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
}

void	mlx_xpm(void *mlx, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img)
		return ;
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);
	if (!img->addr)
		return ;
	img->ppl = img->size_line / (img->bpp / 8);
}

void	mlx_vimg(void *mlx, t_img *img)
{
	img->img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img->img)
		return ;
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);
	if (!img->addr)
		return ;
	img->ppl = img->size_line / (img->bpp / 8);
	img->height = WIN_HEIGHT;
	img->width = WIN_WIDTH;
}


bool	img_init(t_cub *cub)
{
	void	*mlx;

	mlx = cub->mlx.mlx;
	mlx_vimg(mlx, &cub->img.display);
	mlx_xpm(mlx, MM_FRAME_PATH, &cub->img.mm_frame);
	mlx_xpm(mlx, MM_WALL_PATH, &cub->img.mm_wall);
	mlx_xpm(mlx, MM_FLOOR_PATH, &cub->img.mm_floor);
	mlx_xpm(mlx, cub->parse.n_wall, &cub->img.n_wall);
	mlx_xpm(mlx, cub->parse.s_wall, &cub->img.s_wall);
	mlx_xpm(mlx, cub->parse.e_wall, &cub->img.e_wall);
	mlx_xpm(mlx, cub->parse.w_wall, &cub->img.w_wall);
	if (!cub->img.mm_frame.img || !cub->img.mm_wall.img || !cub->img.mm_floor.img
		|| !cub->img.n_wall.img || !cub->img.s_wall.img || !cub->img.e_wall.img
		|| !cub->img.w_wall.img || !cub->img.display.img)
		return (err_msg(ERR_IMG), false);
	return (true);
}
