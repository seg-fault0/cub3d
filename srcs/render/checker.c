/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:52:14 by wimam             #+#    #+#             */
/*   Updated: 2025/10/12 12:53:55 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_check(t_cub *cub)
{
	if (cub->dda.sideDist.x < cub->dda.sideDist.y)
	{
		cub->dda.sideDist.x += cub->dda.delta.x;
		cub->dda.map.x += cub->dda.step.x;
		cub->dda.side = 0;
	}
	else
	{
		cub->dda.sideDist.y += cub->dda.delta.y;
		cub->dda.map.y += cub->dda.step.y;
		cub->dda.side = 1;
	}
}

void	check_raydir(t_dda *ray, t_player *player)
{
	if (ray->rayDir.x < 0)
	{
		ray->step.x = -1;
		ray->sideDist.x = (player->pos.x - ray->map.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sideDist.x = (ray->map.x + 1 - player->pos.x) * ray->delta.x;
	}
	if (ray->rayDir.y < 0)
	{
		ray->step.y = -1;
		ray->sideDist.y = (player->pos.y - ray->map.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sideDist.y = (ray->map.y + 1 - player->pos.y) * ray->delta.y;
	}
}
