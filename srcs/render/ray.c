#include "cub.h"

void	init_ray(t_dda *ray, t_player *player, int x)
{
	ft_memset(ray, 0, sizeof(t_dda));
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->raydir.x = player->dir.x + player->plane.x * ray->camera_x;
	ray->raydir.y = player->dir.y + player->plane.y * ray->camera_x;
	ray->map = (t_ivector2) {player->pos.x, player->pos.y};
	if (ray->raydir.x == 0)
		ray->deltadistx = 1e30;
	else
		ray->deltadistx = fabs(1.0 / ray->raydir.x);
	if (ray->raydir.y == 0)
		ray->deltadisty = 1e30;
	else
		ray->deltadisty = fabs(1.0 / ray->raydir.y);
}

