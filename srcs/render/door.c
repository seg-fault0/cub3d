/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:45:39 by wimam             #+#    #+#             */
/*   Updated: 2025/10/14 09:48:37 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_door(t_cub *cub, int x)
{
	int		y;
	int		color;
	double	wall_x;
	int		tex_x;

	cub->dda.tex.step = 1.0 * TEXTERE_HEIGHT / cub->dda.line_height;
	cub->dda.tex.pos = (cub->dda.draw.start - WIN_HEIGHT / 2
			+ cub->dda.line_height / 2) * cub->dda.tex.step;
	cub->dda.tex_num = 4;
	if (cub->dda.side == 0)
		wall_x = cub->player.pos.y + cub->dda.wall.dist * cub->dda.ray_dir.y;
	else
		wall_x = cub->player.pos.x + cub->dda.wall.dist * cub->dda.ray_dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)TEXTERE_WIDHT);
	if (cub->dda.side == 0 && cub->dda.ray_dir.x > 0)
		tex_x = TEXTERE_WIDHT - tex_x - 1;
	if (cub->dda.side == 1 && cub->dda.ray_dir.y < 0)
		tex_x = TEXTERE_WIDHT - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= TEXTERE_WIDHT)
		tex_x = TEXTERE_WIDHT - 1;
	y = cub->dda.draw.start;
	while (y < cub->dda.draw.end)
	{
		cub->dda.tex.y = (int)cub->dda.tex.pos & (TEXTERE_HEIGHT - 1);
		cub->dda.tex.pos += cub->dda.tex.step;
		color = cub->textures[cub->dda.tex_num]
		[TEXTERE_WIDHT * cub->dda.tex.y + tex_x];
		if (cub->dda.side == 1)
			color = (color >> 1) & 8355711;
		put_pixel_to_img(&cub->img.display, x, y, color);
		y++;
	}
}
