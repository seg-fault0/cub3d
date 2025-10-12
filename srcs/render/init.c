/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:59:30 by wimam             #+#    #+#             */
/*   Updated: 2025/10/12 16:59:30 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_ray(t_dda *ray, t_player *player, int x)
{
	ft_memset(ray, 0, sizeof(t_dda));
	ray->camera = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir.x = player->dir.x + player->plane.x * ray->camera;
	ray->ray_dir.y = player->dir.y + player->plane.y * ray->camera;
	ray->map = (t_ivector2){player->pos.x, player->pos.y};
	if (ray->ray_dir.x == 0)
		ray->delta.x = 1e30;
	else
		ray->delta.x = fabs(1.0 / ray->ray_dir.x);
	if (ray->ray_dir.y == 0)
		ray->delta.y = 1e30;
	else
		ray->delta.y = fabs(1.0 / ray->ray_dir.y);
}
