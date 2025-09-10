/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:42:26 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 09:19:54 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_mlx(t_mlx mlx)
{
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
}

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
