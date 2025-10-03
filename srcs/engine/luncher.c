/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:45:04 by wimam             #+#    #+#             */
/*   Updated: 2025/09/12 12:37:44 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	luncher(t_cub *cub)
{
	render_world(cub);
	mlx_hook(cub->mlx.win, 17, 0, ft_exit, cub);
	mlx_hook(cub->mlx.win, 2, 1L << 0, key_press, &cub->key);
	mlx_hook(cub->mlx.win, 3, 1L << 1, key_release, &cub->key);
	mlx_hook(cub->mlx.win, 6, 1L << 6, mouse_move, &cub->player);
	mlx_loop_hook(cub->mlx.mlx, game_cycle, cub);
	mlx_loop(cub->mlx.mlx);
}
