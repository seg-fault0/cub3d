/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:45:04 by wimam             #+#    #+#             */
/*   Updated: 2025/09/08 22:58:39 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	luncher(t_cub *cub)
{
	mlx_hook(cub->mlx.win, 17, 0, ft_exit, cub);
	mlx_key_hook(cub->mlx.win, player_input, cub);
	mlx_loop(cub->mlx.mlx);
}
