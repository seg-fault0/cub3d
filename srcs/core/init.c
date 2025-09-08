/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:18:02 by wimam             #+#    #+#             */
/*   Updated: 2025/09/09 00:27:45 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	init_cub(t_cub *cub, int ac, char **av)
{
	ft_memset(cub, 0, sizeof(t_cub));
	if (ft_mlx_init(&cub->mlx) == false)
		return (free_mlx(&cub->mlx), false);
	return (true);
}
