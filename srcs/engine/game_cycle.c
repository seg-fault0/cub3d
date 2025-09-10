/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 04:12:52 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 12:01:37 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	game_cycle(t_cub *cub)
{
	static unsigned int	fps;

	if (fps == UINT_MAX)
		fps = 0;
	if ((fps % UPDATE_RATE) == 0)
	{
		input_hander(cub);
		minimap(cub);
		player(cub);
	}
	return (fps++, 0);
}
