/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:42:09 by wimam             #+#    #+#             */
/*   Updated: 2025/09/26 22:35:41 by mohmajdo         ###   ########.fr       */
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
	if (cub->img.img)
		mlx_destroy_image(cub->mlx.mlx, cub->img.img);
}

void	*mlx_xpm(void *mlx, char *path, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx, path, width, height));
}

// static int	*xpm_to_buffer(t_cub *cub, char *path, int *tex_size)
// {
// 	void	*tmp_img;
// 	char	*tmp_addr;
// 	int		*buffer;
// 	int		x;
// 	int		y;

// 	tmp_img = mlx_xpm(cub->mlx.mlx, path, tex_size, tex_size);
// 	if (!tmp_img)
// 		return (NULL);
// 	tmp_addr = mlx_get_data_addr(tmp_img, &cub->img.bits_per_pixel, &cub->img.size_line, &cub->img.endian);
// 	buffer = calloc(1, sizeof(int) * (*tex_size) * (*tex_size));
// 	if (!buffer)
// 	{
// 		mlx_destroy_image(cub->mlx.mlx, tmp_img);
// 		return (NULL);
// 	}
// 	y = -1;
// 	while (++y < *tex_size)
// 	{
// 		x = -1;
// 		while (++x < *tex_size)
// 			buffer[y * (*tex_size) + x] = ((int *)tmp_addr)[y * (*tex_size) + x];
// 	}
// 	mlx_destroy_image(cub->mlx.mlx, tmp_img);
// 	return (buffer);
// }

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
	cub->img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cub->img.img)
		return (err_msg(ERR_IMG), false);
	cub->img.addr = mlx_get_data_addr(cub->img.img, 
					   &cub->img.bits_per_pixel,
					   &cub->img.size_line,
					   &cub->img.endian);
	if (!cub->img.addr)
		return (err_msg(ERR_IMG), false);
	return (true);
}