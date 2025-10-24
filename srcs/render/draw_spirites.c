#include "../../includes/cub.h"

static void	draw_sprite_stripe(t_cub *cub, t_sprite *sprite)
{
	int				y;
	int				tex_x;
	int				tex_y;
	int				d;
	unsigned int	color;

	tex_x = (int)((cub->sprites.stripe - (-cub->sprites.sprite_width / 2 + cub->sprites.sprite_screen_x))
				  * TEXTERE_WIDHT / cub->sprites.sprite_width);
	y = cub->sprites.draw_start_y - 1;
	while (++y < cub->sprites.draw_end_y)
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
	cub->sprites.sprite_x = sprite->x - cub->player.pos.x;
	cub->sprites.sprite_y = sprite->y - cub->player.pos.y;
	cub->sprites.inv_det = 1.0 / (cub->player.plane.x * cub->player.dir.y - 
					 cub->player.dir.x * cub->player.plane.y);
	cub->sprites.transform_x = cub->sprites.inv_det * (cub->player.dir.y * cub->sprites.sprite_x - 
							 cub->player.dir.x * cub->sprites.sprite_y);
	cub->sprites.transform_y = cub->sprites.inv_det * (-cub->player.plane.y * cub->sprites.sprite_x + 
							  cub->player.plane.x * cub->sprites.sprite_y);
	if (cub->sprites.transform_y <= 0)
		return;
	cub->sprites.sprite_screen_x = (int)((WIN_WIDTH / 2) * (1 + cub->sprites.transform_x / cub->sprites.transform_y));
	cub->sprites.sprite_height = abs((int)(WIN_HEIGHT / cub->sprites.transform_y));
	cub->sprites.sprite_width = abs((int)(WIN_HEIGHT / cub->sprites.transform_y));	
	cub->sprites.draw_start_y = -cub->sprites.sprite_height / 2 + WIN_HEIGHT / 2;
	if (cub->sprites.draw_start_y < 0)
		cub->sprites.draw_start_y = 0;
	cub->sprites.draw_end_y = cub->sprites.sprite_height / 2 + WIN_HEIGHT / 2;
	if (cub->sprites.draw_end_y >= WIN_HEIGHT)
		cub->sprites.draw_end_y = WIN_HEIGHT - 1;
	cub->sprites.draw_start_x = -cub->sprites.sprite_width / 2 + cub->sprites.sprite_screen_x;
	if (cub->sprites.draw_start_x < 0)
		cub->sprites.draw_start_x = 0;
	cub->sprites.draw_end_x = cub->sprites.sprite_width / 2 + cub->sprites.sprite_screen_x;
	if (cub->sprites.draw_end_x >= WIN_WIDTH)
		cub->sprites.draw_end_x = WIN_WIDTH - 1;
	cub->sprites.stripe = cub->sprites.draw_start_x - 1;
	while (++cub->sprites.stripe < cub->sprites.draw_end_x)
	{
		if (cub->sprites.stripe >= 0 && cub->sprites.stripe < WIN_WIDTH && 
			cub->sprites.transform_y < cub->sprites.zbuffer[cub->sprites.stripe])
		{
			draw_sprite_stripe(cub, sprite);
		}
	}
}

void	render_sprites(t_cub *cub)
{
	int	i;

	if (cub->sprites.count == 0)
		return;
	sort_sprites(cub);
	i = -1;
	while (++i < cub->sprites.count)
	{
		draw_one_sprite(cub, cub->sprites.order[i]);
	}
}