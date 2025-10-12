#include "cub.h"

void	init_ray(t_dda *ray, t_player *player, int x)
{
	ray->deltadistx = 0;
	ray->deltadisty = 0;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->map = (t_ivector2){0, 0};
	ray->raydir_x = 0;
	ray->raydir_y = 0;
	ray->camera_x = 0;
	ray->side = 0;
	ray->walldist = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->raydir_x = player->dir.x + player->plane.x * ray->camera_x;
	ray->raydir_y = player->dir.y + player->plane.y * ray->camera_x;
	ray->map = (t_ivector2) {player->pos.x, player->pos.y};
	if (ray->raydir_x == 0)
		ray->deltadistx = 1e30;
	else
		ray->deltadistx = fabs(1.0 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->deltadisty = 1e30;
	else
		ray->deltadisty = fabs(1.0 / ray->raydir_y);
}

