/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:18:02 by wimam             #+#    #+#             */
/*   Updated: 2025/09/09 05:00:54 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	setup_cub(t_cub *cub, char **av)
{
	ft_memset(cub, 0, sizeof(t_cub));
	if (ft_mlx_init(&cub->mlx) == false)
		return (false);
	if (map_init(cub, av[1]) == false)
		return (free_mlx(&cub->mlx), false);
	return (true);
}
