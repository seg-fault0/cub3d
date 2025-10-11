/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:31:34 by wimam             #+#    #+#             */
/*   Updated: 2025/10/09 02:48:58 by mohmajdo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_pixel(void *img, int x, int y)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		offset;
	int		color;

	data = mlx_get_data_addr(img, &bpp, &size_line, &offset);
	offset = y * size_line + x * (bpp / 8);
	color = *(int *)(data + offset);
	return (color);
}

static void	draw_no_bg(t_cub *cub, t_img img, int x0, int y0)
{
	int	x;
	int	y;
	int	color;
	int	transp;

	transp = 0xFF00FF;
	y = 0;
	while (y < img.height)
	{
		x = 0;
		while (x < img.width)
		{
			color = get_pixel(img.p, x, y);
			if (color != transp)
				mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, x0 + x, y0 + y, color);
			x++;
		}
		y++;
	}
}

void	mlx_draw(t_cub *cub, int img, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = cub->mlx.mlx;
	win = cub->mlx.win;
	if (img == MM_FLOOR)
		mlx_put_image_to_window(mlx, win, cub->img.mm_floor, x, y);
	else if (img == MM_WALL && mlx && win && cub->img.mm_wall)
		mlx_put_image_to_window(mlx, win, cub->img.mm_wall, x, y);
	else if (img == MM_FRAME)
		draw_no_bg(cub, cub->img.mm_frame, x, y);
}
