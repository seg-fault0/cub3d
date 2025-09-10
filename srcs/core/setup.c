/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:18:02 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 20:29:51 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	b_zero(t_cub *cub)
{
	ft_memset(cub, 0, sizeof(t_cub));
	ft_memset(&cub->img, 0, sizeof(t_imgs));
	ft_memset(&cub->mlx, 0, sizeof(t_mlx));
	ft_memset(&cub->key, 0, sizeof(t_key));
	ft_memset(&cub->player, 0, sizeof(t_player));
	imgs_bzero(&cub->img);
}

bool	setup_cub(t_cub *cub, char **av)
{
	b_zero(cub);
	if (ft_mlx_init(&cub->mlx) == false)
		return (false);
	if (map_init(cub, av[1]) == false)
		return (free_mlx(cub->mlx), false);
	if (img_init(cub) == false)
		return (free_map(cub->map), free_mlx(cub->mlx), false);
	if (player_init(cub) == false)
		return (free_img(cub), free_map(cub->map), free_mlx(cub->mlx), false);
	return (true);
}
