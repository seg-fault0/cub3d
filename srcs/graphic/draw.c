/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:31:34 by wimam             #+#    #+#             */
/*   Updated: 2025/11/01 15:38:18 by wimam            ###   ########.fr       */
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
	char	*src_pxl;

	y = 0;
	while (y < src->height)
	{
		x = 0;
		while (x < src->width)
		{
			if (px + x >= 0 && py + y >= 0
				&& px + x < dst->width && py + y < dst->height)
			{
				src_pxl = src->addr + (y * src->size_line + x * (src->bpp / 8));
				color = *(unsigned int *)src_pxl;
				put_pixel_to_img(dst, px + x, py + y, color);
			}
			x++;
		}
		y++;
	}
}
