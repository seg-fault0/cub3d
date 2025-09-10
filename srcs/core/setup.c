/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:18:02 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 08:21:29 by wimam            ###   ########.fr       */
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

bool	setup_cub(t_cub *cub, char **av)
{
	ft_memset(cub, 0, sizeof(t_cub));
	if (ft_mlx_init(&cub->mlx) == false)
		return (false);
	if (map_init(cub, av[1]) == false)
		return (free_mlx(&cub->mlx), false);
	return (true);
}
