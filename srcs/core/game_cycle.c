/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 04:12:52 by wimam             #+#    #+#             */
/*   Updated: 2025/09/09 04:16:52 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	input_hander(t_cub *cub)
{
	if (cub->key.esq == true)
		ft_exit(cub, 0);
	if (cub->key.w == true)
		write(1, "w", 1);
}

int	game_cycle(t_cub *cub)
{
	input_hander(cub);
	return (0);
}
