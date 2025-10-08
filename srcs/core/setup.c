/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmajdo <mohmajdo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:18:02 by wimam             #+#    #+#             */
/*   Updated: 2025/10/07 23:31:35 by mohmajdo         ###   ########.fr       */
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
	ft_memset(&cub->parse, 0, sizeof(t_parse));
	imgs_bzero(&cub->img);
}

bool	setup_cub(t_cub *cub, char **av)
{
	b_zero(cub);
	if (ft_mlx_init(&cub->mlx) == false
		||parse(cub, av[1]) == false
		||ft_img_init(cub) == false
		||init_scr_img(cub) == false
		||player_init(cub) == false)
		return (ft_exit(cub, 1), false);
	return (true);
}
