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
}

void	*mlx_xpm(void *mlx, char *path, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx, path, width, height));
}

bool	img_init(t_cub *cub)
{
	void	*mlx;

	mlx = cub->mlx.mlx;
	cub->img.mm_frame.p = mlx_xpm(mlx, MM_FRAME_PATH, &cub->img.mm_frame.width, &cub->img.mm_frame.height);
	cub->img.mm_wall = mlx_xpm(mlx, MM_WALL_PATH, cub->img.size, cub->img.size);
	cub->img.mm_floor = mlx_xpm(mlx, MM_FLOOR_PATH, cub->img.size, cub->img.size);
	cub->img.n_wall = mlx_xpm(mlx, cub->parse.n_wall, cub->img.size, cub->img.size);
	cub->img.s_wall = mlx_xpm(mlx, cub->parse.s_wall, cub->img.size, cub->img.size);
	cub->img.e_wall = mlx_xpm(mlx, cub->parse.e_wall, cub->img.size, cub->img.size);
	cub->img.w_wall = mlx_xpm(mlx, cub->parse.w_wall, cub->img.size, cub->img.size); // check fails
	if (!cub->img.mm_frame.p || !cub->img.mm_wall || !cub->img.mm_floor
		|| !cub->img.n_wall || !cub->img.s_wall || !cub->img.e_wall
		|| !cub->img.w_wall)
		return (err_msg(ERR_IMG), false);
	cub->img.textere[0] = xpm_to_image(cub, cub->img.n_wall);
	cub->img.textere[1] = xpm_to_image(cub, cub->img.s_wall);
	cub->img.textere[2] = xpm_to_image(cub, cub->img.e_wall);
	cub->img.textere[3] = xpm_to_image(cub, cub->img.w_wall);
	return (true);
}

int	*xpm_to_image(t_cub *cub, void *img_addr)
{
	int	x;
	int	y;
	int	*buffer;
	int *addr;
	int pixels_per_line;

	buffer = ft_calloc(1, sizeof(int) * cub->img.size * cub->img.size);
	if (!buffer)
		return(NULL);
	addr = (int *)mlx_get_data_addr(img_addr, &cub->img.bits_per_pixel, &cub->img.size_line, &cub->img.endian);
	if (!addr)
		return (free(buffer), NULL);
	x = 0;
	pixels_per_line = cub->img.size_line / sizeof(int);
	while (x < cub->img.size)
	{
		y = 0;
		while (y < cub->img.size)
		{
			buffer[x * cub->img.size + y] = addr[x * pixels_per_line + y];
			++y; 
		}
		++x;
	}
	return (buffer);
}
