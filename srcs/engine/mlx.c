/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:42:26 by wimam             #+#    #+#             */
/*   Updated: 2025/11/10 20:34:15 by mohmajdo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_mlx(t_mlx mlx)
{
	if (mlx.win)
		mlx_destroy_window(mlx.mlx, mlx.win);
	if (mlx.mlx)
		mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
}

bool	ft_mlx_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (err_msg(ERR_MLX), false);
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!mlx->win)
		return (err_msg(ERR_WIN), false);
	return (true);
}
