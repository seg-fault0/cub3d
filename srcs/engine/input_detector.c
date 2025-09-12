/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:48:34 by wimam             #+#    #+#             */
/*   Updated: 2025/09/12 12:37:36 by wimam            ###   ########.fr       */
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
	return (0);
}

int	mouse_move(int x, int y, t_player *player)
{
	static int	old_x;

	(void) y;
	if (x > old_x)
		player->angle += ROTATION_SPEED;
	else if (x < old_x)
		player->angle -= ROTATION_SPEED;
	old_x = x;
	return (0);
}
