/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:48:34 by wimam             #+#    #+#             */
/*   Updated: 2025/10/11 21:13:20 by mohmajdo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_press(int key, t_key *keys)
{
	if (key == ESC_KEY)
		keys->esq = true;
	if (key == W_KEY)
		keys->w = true;
	if (key == A_KEY)
		keys->a = true;
	if (key == S_KEY)
		keys->s = true;
	if (key == D_KEY)
		keys->d = true;
	if (key == L_ARR)
		keys->l_arr = true;
	if (key == R_ARR)
		keys->r_arr = true;
	return (0);
}

int	key_release(int key, t_key *keys)
{
	if (key == W_KEY)
		keys->w = false;
	if (key == A_KEY)
		keys->a = false;
	if (key == S_KEY)
		keys->s = false;
	if (key == D_KEY)
		keys->d = false;
	if (key == L_ARR)
		keys->l_arr = false;
	if (key == R_ARR)
		keys->r_arr = false;
	return (0);
}

void	rotate_vectores(t_player *player, double delta_x)
{
	int		x;
	int		y;

	x = player->dir_x;
	y = player->dir_y;
	player->dir_x = x * cos(delta_x) - y * sin(delta_x);
	player->dir_y = x * sin(delta_x) + y * cos(delta_x);
	x = player->plane_x;
	y = player->plane_y;
	player->plane_x = x * cos(delta_x) - y * sin(delta_x);
	player->plane_y = x * sin(delta_x) + y * cos(delta_x);
}

int	mouse_move(int x, int y, t_player *player)
{
	static int	old_x;

	(void) y;
	if (x > old_x)
		player->angle += (ROTATION_SPEED / 15);
	else if (x < old_x)
		player->angle -= (ROTATION_SPEED / 15);
	old_x = x;
	return (0);
}
