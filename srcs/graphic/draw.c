/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:31:34 by wimam             #+#    #+#             */
/*   Updated: 2025/10/25 16:02:13 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (color == TRANSP)
		return ;
	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	pixel = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	draw_img_to_img(t_img *dst, t_img *src, int px, int py)
{
	int		x;
	int		y;
	int		color;
	char	*dst_pixel;
	char	*src_pixel;

	y = 0;
	while (y < src->height)
	{
		if (py + y >= 0 && py + y < dst->height)
		{
			x = 0;
			while (x < src->width)
			{
				if (px + x >= 0 && px + x < dst->width)
				{
					src_pixel = src->addr + (y * src->size_line + x * (src->bpp / 8));
					color = *(unsigned int *)src_pixel;
					if (color != TRANSP)
					{
						dst_pixel = dst->addr
							+ ((py + y) * dst->size_line + (px + x) * (dst->bpp / 8));
						*(unsigned int *)dst_pixel = color;
					}
				}
				x++;
			}
		}
		y++;
	}
}
