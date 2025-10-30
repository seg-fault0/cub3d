/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_spirites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 16:54:22 by wimam             #+#    #+#             */
/*   Updated: 2025/10/30 22:51:56 by mohmajdo         ###   ########.fr       */
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

	tex_x = (int)((cub->sprites.stripe - (-cub->sprites.sprite_width / 2 
			+ cub->sprites.sprite_screen_x)) * TEXTERE_WIDHT / cub->sprites.sprite_width);
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

static void	draw_one_sprite(t_cub *cub, int idx)
{
	t_sprite	*sprite;
	t_animation	*s;
	t_player	*p;

	sprite = &cub->sprites.sprites[idx];
	s = &cub->sprites;
	p = &cub->player;
	s->sprite.x = sprite->pos.x - p->pos.x;
	s->sprite.y = sprite->pos.y - p->pos.y;
	s->inv_det = 1.0 / (p->plane.x * p->dir.y - p->dir.x * p->plane.y);
	s->transform.x = s->inv_det * (p->dir.y * s->sprite.x - p->dir.x * s->sprite.y);
	s->transform.y = s->inv_det * (-p->plane.y * s->sprite.x + p->plane.x * s->sprite.y);
	if (s->transform.y <= 0)
		return ;
	s->sprite_screen_x = (int)((WIN_WIDTH / 2) * (1 + s->transform.x / s->transform.y));
	s->sprite_height = abs((int)(WIN_HEIGHT / s->transform.y));
	s->sprite_width = s->sprite_height;
	s->draw_start.y = fmax(-s->sprite_height / 2 + WIN_HEIGHT / 2, 0);
	s->draw_end.y = fmin(s->sprite_height / 2 + WIN_HEIGHT / 2, WIN_HEIGHT - 1);
	s->draw_start.x = fmax(-s->sprite_width / 2 + s->sprite_screen_x, 0);
	s->draw_end.x = fmin(s->sprite_width / 2 + s->sprite_screen_x, WIN_WIDTH - 1);
	s->stripe = s->draw_start.x - 1;
	while (++s->stripe < s->draw_end.x)
	{
		if (s->transform.y < s->zbuffer[s->stripe])
			draw_sprite_stripe(cub, sprite);
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
		draw_one_sprite(cub, cub->sprites.order[i]);
}
