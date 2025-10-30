/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:51:32 by wimam             #+#    #+#             */
/*   Updated: 2025/10/30 04:41:38 by mohmajdo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_tex_num(t_cub *cub, int hit)
{
	if (hit == 2)
	{
		cub->dda.tex_num = 4;
		return ;
	}
	if (cub->dda.side == 0)
	{
		if (cub->dda.ray_dir.x > 0)
			cub->dda.tex_num = 2;
		else
			cub->dda.tex_num = 3;
	}
	else
	{
		if (cub->dda.ray_dir.y > 0)
			cub->dda.tex_num = 1;
		else
			cub->dda.tex_num = 0;
	}
}

static int	calculate_tex_x(t_cub *cub)
{
	double	wall_x;
	int		tex_x;

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
	return (tex_x);
}

static void	draw_wall_stripe(t_cub *cub, int x, int hit)
{
	int		y;
	int		color;
	int		tex_x;

	cub->dda.tex.step = 1.0 * TEXTERE_HEIGHT / cub->dda.line_height;
	cub->dda.tex.pos = (cub->dda.draw.start - WIN_HEIGHT / 2
			+ cub->dda.line_height / 2) * cub->dda.tex.step;
	get_tex_num(cub, hit);
	tex_x = calculate_tex_x(cub);
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

void	wall_cast(t_cub *cub)
{
	int	hit;
	int	x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		init_ray(&cub->dda, &cub->player, x);
		check_raydir(&cub->dda, &cub->player);
		hit = 0;
		while (hit == 0)
		{
			ft_check(cub);
			if (cub->dda.map.x >= 0 && cub->dda.map.y >= 0
				&& cub->dda.map.y < cub->parse.max_map_y
				&& cub->dda.map.x < ft_strlen(cub->parse.map[cub->dda.map.y]))
			{
				if ((cub->parse.map[cub->dda.map.y][cub->dda.map.x] == '1'
					|| cub->parse.map[cub->dda.map.y][cub->dda.map.x] == '\n'))
					hit = 1;
				else if (cub->parse.map[cub->dda.map.y][cub->dda.map.x] == 'C')
					hit = 2;
			}
		}
		calc_line_height(&cub->dda);
		calc_wall_texture_x(&cub->dda, &cub->player);
		cub->sprites.zbuffer[x] = cub->dda.wall.dist;
		draw_wall_stripe(cub, x, hit);
	}
}
