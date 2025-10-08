/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 04:12:52 by wimam             #+#    #+#             */
/*   Updated: 2025/10/08 03:21:09 by mohmajdo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define UPDATE_RATE 5000

// int	game_cycle(t_cub *cub)
// {
// 	static unsigned int	fps;

// 	if (fps == UINT_MAX)
// 		fps = 0;
// 	if ((fps % UPDATE_RATE) == 0)
// 	{
// 		render_world(cub);
// 		// minimap(cub);
// 		player(cub);
// 	}
// 	return (fps++, 0);
// }

void handle_movement(t_cub *cub, double move_speed, double rot_speed)
{
    if (cub->key.w)
    {
        double new_x = cub->player.xp + cub->player.dir_x * move_speed;
        double new_y = cub->player.yp + cub->player.dir_y * move_speed;
        
        if (cub->parse.map[(int)cub->player.yp][(int)new_x] == '0')
            cub->player.xp = new_x;
        if (cub->parse.map[(int)new_y][(int)cub->player.xp] == '0')
            cub->player.yp = new_y;
    }
    if (cub->key.s)
    {
        double new_x = cub->player.xp - cub->player.dir_x * move_speed;
        double new_y = cub->player.yp - cub->player.dir_y * move_speed;
        
        if (cub->parse.map[(int)cub->player.yp][(int)new_x] == '0')
            cub->player.xp = new_x;
        if (cub->parse.map[(int)new_y][(int)cub->player.xp] == '0')
            cub->player.yp = new_y;
    }
    if (cub->key.d)
    {
        double old_dir_x = cub->player.dir_x;
        cub->player.dir_x = cub->player.dir_x * cos(-rot_speed) 
                          - cub->player.dir_y * sin(-rot_speed);
        cub->player.dir_y = old_dir_x * sin(-rot_speed) 
                          + cub->player.dir_y * cos(-rot_speed);
        
        double old_plane_x = cub->player.plane_x;
        cub->player.plane_x = cub->player.plane_x * cos(-rot_speed) 
                            - cub->player.plane_y * sin(-rot_speed);
        cub->player.plane_y = old_plane_x * sin(-rot_speed) 
                            + cub->player.plane_y * cos(-rot_speed);
    }
    if (cub->key.a)
    {
        double old_dir_x = cub->player.dir_x;
        cub->player.dir_x = cub->player.dir_x * cos(rot_speed) 
                          - cub->player.dir_y * sin(rot_speed);
        cub->player.dir_y = old_dir_x * sin(rot_speed) 
                          + cub->player.dir_y * cos(rot_speed);
        
        double old_plane_x = cub->player.plane_x;
        cub->player.plane_x = cub->player.plane_x * cos(rot_speed) 
                            - cub->player.plane_y * sin(rot_speed);
        cub->player.plane_y = old_plane_x * sin(rot_speed) 
                            + cub->player.plane_y * cos(rot_speed);
    }
}

int game_cycle(t_cub *cub)
{
    static clock_t old_time = 0;
    clock_t current_time;
    double frame_time;
    double move_speed;
    double rot_speed;

    current_time = clock();
    if (old_time == 0)
        old_time = current_time;
    frame_time = (double)(current_time - old_time) / CLOCKS_PER_SEC;
    old_time = current_time;
    move_speed = frame_time * 3.0;
    rot_speed = frame_time * 2.0;
    handle_movement(cub, move_speed, rot_speed);
    render_world(cub);
    return (0);
}
