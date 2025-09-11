/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:48:34 by wimam             #+#    #+#             */
/*   Updated: 2025/09/11 19:07:17 by wimam            ###   ########.fr       */
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

void	input_hander(t_cub *cub)
{
	if (cub->key.esq == true)
		ft_exit(cub, 0);
	if (cub->key.w == true)
		cub->player.yp --;
	if (cub->key.s == true)
		cub->player.yp ++;
	if (cub->key.a == true)
		cub->player.xp --;
	if (cub->key.d == true)
		cub->player.xp ++;
	if (cub->key.d == true || cub->key.a == true || cub->key.s == true || cub->key.w == true)
		printf("yp = %f | xp = %f\n", cub->player.yp, cub->player.xp);
}
