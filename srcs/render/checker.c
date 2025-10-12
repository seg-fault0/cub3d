/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:52:14 by wimam             #+#    #+#             */
/*   Updated: 2025/10/12 16:59:04 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_check(t_cub *cub)
{
	if (cub->dda.side_dist.x < cub->dda.side_dist.y)
	{
		cub->dda.side_dist.x += cub->dda.delta.x;
		cub->dda.map.x += cub->dda.step.x;
		cub->dda.side = 0;
	}
	else
	{
		cub->dda.side_dist.y += cub->dda.delta.y;
		cub->dda.map.y += cub->dda.step.y;
		cub->dda.side = 1;
	}
}

void	check_raydir(t_dda *ray, t_player *player)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->pos.x - ray->map.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1 - player->pos.x) * ray->delta.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->pos.y - ray->map.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1 - player->pos.y) * ray->delta.y;
	}
}
