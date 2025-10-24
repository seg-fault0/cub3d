#include "../../includes/cub.h"

static void	count_sprites(t_cub *cub)
{
	int	i;
	int	j;
	int	sprite_count;

	sprite_count = 0;
	i = -1;
	while (++i < cub->parse.max_map_y)
	{
		j = -1;
		while (cub->parse.map[i][++j])
		{
			if (cub->parse.map[i][j] == 'D')
				sprite_count++;
		}
	}
	cub->sprites.count = sprite_count;
	cub->sprites.sprites = malloc(sizeof(t_sprite) * sprite_count);
	cub->sprites.zbuffer = malloc(sizeof(double) * WIN_WIDTH);
	cub->sprites.order = malloc(sizeof(int) * sprite_count);
	cub->sprites.distance = malloc(sizeof(double) * sprite_count);
}

bool	init_sprite_system(t_cub *cub)
{
	int	i;
	int	j;
	int	idx;
	count_sprites(cub);
	idx = 0;
	i = -1;
	while (++i < cub->parse.max_map_y)
	{
		j = -1;
		while (cub->parse.map[i][++j])
		{
			if (cub->parse.map[i][j] == 'D')
			{
				cub->sprites.sprites[idx].x = j + 0.5;
				cub->sprites.sprites[idx].y = i + 0.5;
				cub->sprites.sprites[idx].texture = 5;
				cub->sprites.sprites[idx].type = 2;
				idx++;
			}
		}
	}
	return (true);
}

static void	spirite_ordre(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < cub->sprites.count)
	{
		cub->sprites.order[i] = i;
		cub->sprites.distance[i] = ((cub->player.pos.x - 
			cub->sprites.sprites[i].x) * (cub->player.pos.x - 
			cub->sprites.sprites[i].x) + (cub->player.pos.y - 
			cub->sprites.sprites[i].y) * (cub->player.pos.y - 
			cub->sprites.sprites[i].y));
	}
}

void	sort_sprites(t_cub *cub)
{
	int		i;
	int		j;
	int		temp_order;
	double	temp_dist;

	spirite_ordre(cub);
	i = -1;
	while (++i < cub->sprites.count - 1)
	{
		j = -1;
		while (++j < cub->sprites.count - 1 - i)
		{
			if (cub->sprites.distance[cub->sprites.order[j]] < 
				cub->sprites.distance[cub->sprites.order[j + 1]])
			{
				temp_order = cub->sprites.order[j];
				temp_dist = cub->sprites.distance[j];
				cub->sprites.order[j] = cub->sprites.order[j + 1];
				cub->sprites.distance[j] = cub->sprites.distance[j + 1];
				cub->sprites.order[j + 1] = temp_order;
				cub->sprites.distance[j + 1] = temp_dist;
			}
		}
	}
}
