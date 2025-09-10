/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:31:34 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 11:38:31 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_pixel(void *img, int x, int y)
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

void	draw_img(t_cub *cub, t_img img, int x0, int y0)
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
