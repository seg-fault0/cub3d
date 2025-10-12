/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 04:12:52 by wimam             #+#    #+#             */
/*   Updated: 2025/10/11 21:10:07 by mohmajdo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define UPDATE_RATE 500

int	game_cycle(t_cub *cub)
{
	static unsigned int	fps;

	if (fps == UINT_MAX)
		fps = 0;
	if ((fps % UPDATE_RATE) == 0)
	{
		render_world(cub);
		minimap(cub);
		player(cub);
	}
	return (fps++, 0);
}

