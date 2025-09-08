/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:27:10 by wimam             #+#    #+#             */
/*   Updated: 2025/09/08 22:58:53 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_exit(t_cub *cub, int code)
{
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	mlx_destroy_display(cub->mlx.mlx);
	exit(code);
	return (0);
}
