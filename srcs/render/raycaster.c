/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:51:32 by wimam             #+#    #+#             */
/*   Updated: 2025/09/16 19:52:47 by mohmajdo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"



// void	draw_wall(t_cub *cub, int x, double walldist)
// {
// 	int	h_line;
// 	int	draw_start;
// 	int	draw_end;

// 	h_line = (WIN_HEIGHT / walldist);
// 	draw_start = WIN_HEIGHT / 2 - h_line / 2;
// 	if (draw_start < 0)
// 		draw_start = 0;
// 	draw_end = h_line / 2 + WIN_HEIGHT / 2;
// 	if (draw_end >= WIN_HEIGHT)
// 		draw_end = WIN_HEIGHT - 1;
// 	for (int y = 0; y < draw_start, y++)
// 		cub->img.data[y * WIN_WIDTH + x] = cub->colors.ceiling;
// 	int wall_color = get_wall_color(cub);
// 	for (int y = drawStart; y <= drawEnd; y++)
// 	    cub->img.data[y * WIN_WIDTH + x] = wall_color;
// 	for (int y = drawEnd + 1; y < WIN_HEIGHT; y++)
//         cub->img.data[y * WIN_WIDTH + x] = cub->colors.floor;
// }

void	check_raydir(t_cub *cub, int *step_x, int *step_y)
{
	if (cub->dda.raydir_x < 0)
	{
		*step_x = -1;
		cub->dda.sidedistx = (cub->player.xp - cub->dda.map_x) * cub->dda.deltadistx;
	}
	else
	{
		*step_x = 1;
		cub->dda.sidedistx = (cub->player.xp - cub->dda.map_x + 1) * cub->dda.deltadistx;
	}
	if (cub->dda.raydir_y < 0)
	{
		*step_y = -1;
		cub->dda.sidedisty = (cub->player.yp - cub->dda.map_y) * cub->dda.deltadisty;
	}
	else
	{
		*step_y = 1;
		cub->dda.sidedisty = (cub->player.yp - cub->dda.map_y + 1) * cub->dda.deltadisty;
	}
}

void	world_raycaster(t_cub *cub)
{
	int	x;
	int	hit;
	int	step_x;
	int	step_y;
	int	walldist;

	x = 0;
	hit = 0;
	while (x < WIN_WIDTH)
	{
		cub->dda.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		cub->dda.raydir_x = cub->player.dir_x + cub->player.plane_x * cub->dda.camera_x;
		cub->dda.raydir_y = cub->player.dir_y + cub->player.plane_y * cub->dda.camera_x;
		cub->dda.map_x = (int)cub->player.xp;
		cub->dda.map_y = (int)cub->player.yp;
		cub->dda.deltadistx = fabs(1.0 / cub->dda.raydir_x);
		cub->dda.deltadisty = fabs(1.0 / cub->dda.raydir_y);
		check_raydir(cub, &step_x, &step_y);
		while (hit == 0)
		{
			hit = 0;
			if (cub->dda.sidedistx < cub->dda.sidedisty)
			{
				cub->dda.sidedistx += cub->dda.deltadistx;
				cub->dda.map_x += step_x;
				cub->dda.side = 0;
			}
			else
			{
				cub->dda.sidedisty += cub->dda.deltadisty;
				cub->dda.map_y += step_y;
				cub->dda.side = 1;
			}
			if (cub->dda.map_x >= 0 && cub->dda.map_y >= 0 &&
    				cub->parse.map[cub->dda.map_y][cub->dda.map_x] != '0')
				hit = 1;
		}
		if (cub->dda.side == 0)
			walldist = cub->dda.sidedistx - cub->dda.deltadistx;
		else
			walldist = cub->dda.sidedisty - cub->dda.deltadisty;
		draw_wall(cub, cub->player.xp,walldist);
		x++;
	}
	return ;
}
