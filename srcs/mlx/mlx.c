/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:42:26 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 08:42:44 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	ft_mlx_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (err_msg(ERR_MLX), false);
	mlx->win = mlx_new_window(mlx->mlx, WIN_WITH, WIN_HEIGHT, "cub3d");
	if (!mlx->win)
		return (err_msg(ERR_WIN), false);
	return (true);
}
