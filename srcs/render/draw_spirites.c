/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_spirites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:54:22 by wimam             #+#    #+#             */
/*   Updated: 2025/10/25 16:56:58 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_sprite_stripe(t_cub *cub, t_sprite *sprite)
{
	int				y;
	int				tex_x;
	int				tex_y;
	int				d;
	unsigned int	color;

	tex_x = (int)((cub->sprites.stripe - (-cub->sprites.sprite_width / 2 + cub->sprites.sprite_screen_x))
			* TEXTERE_WIDHT / cub->sprites.sprite_width);
	y = cub->sprites.draw_start.y - 1;
	while (++y < cub->sprites.draw_end.y)
	{
		d = y * 256 - WIN_HEIGHT * 128 + cub->sprites.sprite_height * 128;
		tex_y = ((d * TEXTERE_HEIGHT) / cub->sprites.sprite_height) / 256;
		color = cub->textures[sprite->texture]
		[TEXTERE_WIDHT * tex_y + tex_x];
		if ((color & 0x00FFFFFF) != 0)
			put_pixel_to_img(&cub->img.display, cub->sprites.stripe, y, color);
	}
}

static void	draw_one_sprite(t_cub *cub, int sprite_idx)
{
	t_sprite	*sprite;

	sprite = &cub->sprites.sprites[sprite_idx];
	cub->sprites.sprite.x = sprite->pos.x - cub->player.pos.x;
	cub->sprites.sprite.y = sprite->pos.y - cub->player.pos.y;
	cub->sprites.inv_det = 1.0 / (cub->player.plane.x * cub->player.dir.y
			-cub->player.dir.x * cub->player.plane.y);
	cub->sprites.transform.x = cub->sprites.inv_det * (cub->player.dir.y * cub->sprites.sprite.x
			- cub->player.dir.x * cub->sprites.sprite.y);
	cub->sprites.transform.y = cub->sprites.inv_det * (-cub->player.plane.y * cub->sprites.sprite.x
			+ cub->player.plane.x * cub->sprites.sprite.y);
	if (cub->sprites.transform.y <= 0)
		return ;
	cub->sprites.sprite_screen_x = (int)((WIN_WIDTH / 2) * (1 + cub->sprites.transform.x / cub->sprites.transform.y));
	cub->sprites.sprite_height = abs((int)(WIN_HEIGHT / cub->sprites.transform.y));
	cub->sprites.sprite_width = abs((int)(WIN_HEIGHT / cub->sprites.transform.y));
	cub->sprites.draw_start.y = -cub->sprites.sprite_height / 2 + WIN_HEIGHT / 2;
	if (cub->sprites.draw_start.y < 0)
		cub->sprites.draw_start.y = 0;
	cub->sprites.draw_end.y = cub->sprites.sprite_height / 2 + WIN_HEIGHT / 2;
	if (cub->sprites.draw_end.y >= WIN_HEIGHT)
		cub->sprites.draw_end.y = WIN_HEIGHT - 1;
	cub->sprites.draw_start.x = -cub->sprites.sprite_width / 2 + cub->sprites.sprite_screen_x;
	if (cub->sprites.draw_start.x < 0)
		cub->sprites.draw_start.x = 0;
	cub->sprites.draw_end.x = cub->sprites.sprite_width / 2 + cub->sprites.sprite_screen_x;
	if (cub->sprites.draw_end.x >= WIN_WIDTH)
		cub->sprites.draw_end.x = WIN_WIDTH - 1;
	cub->sprites.stripe = cub->sprites.draw_start.x - 1;
	while (++cub->sprites.stripe < cub->sprites.draw_end.x)
	{
		if (cub->sprites.stripe >= 0 && cub->sprites.stripe < WIN_WIDTH
			&& cub->sprites.transform.y < cub->sprites.zbuffer[cub->sprites.stripe])
		{
			draw_sprite_stripe(cub, sprite);
		}
	}
}

void	render_sprites(t_cub *cub)
{
	int	i;

	if (cub->sprites.count == 0)
		return ;
	sort_sprites(cub);
	i = -1;
	while (++i < cub->sprites.count)
	{
		draw_one_sprite(cub, cub->sprites.order[i]);
	}
}
