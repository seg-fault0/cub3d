/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 00:29:43 by wimam             #+#    #+#             */
/*   Updated: 2025/11/01 17:18:36 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define STDERR 2

static void	err_msg_nor(int msg)
{
	if (msg == ERR_PLYR_NF)
		ft_putstr_fd("no player has been found\n", STDERR);
	else if (msg == ERR_MAP_NF)
		ft_putstr_fd("map not found\n", STDERR);
	else if (msg == ERR_DOUBLE)
		ft_putstr_fd("double componants\n", STDERR);
}

void	err_msg(int msg)
{
	ft_putstr_fd("ERR : ", STDERR);
	if (msg == ERR_MALLOC)
		ft_putstr_fd("ALLOCATION FAILED\n", STDERR);
	else if (msg == ERR_MLX)
		ft_putstr_fd("MLX FAILED\n", STDERR);
	else if (msg == ERR_WIN)
		ft_putstr_fd("WINDOW FAILED\n", STDERR);
	else if (msg == ERR_AC)
		ft_putstr_fd("usage : ./cub ./path/to/map.cub\n", STDERR);
	else if (msg == ERR_OPEN)
		ft_putstr_fd("open failed\n", STDERR);
	else if (msg == ERR_MAP_SIZE)
		ft_putstr_fd("file is too big\n", STDERR);
	else if (msg == ERR_IMG)
		ft_putstr_fd("image failed to open\n", STDERR);
	else if (msg == ERR_ELMT_NF)
		ft_putstr_fd("element not found\n", STDERR);
	else if (msg == ERR_CLR_FORMAT)
		ft_putstr_fd("wrong clr format\n", STDERR);
	else if (msg == ERR_MAP_BORDER)
		ft_putstr_fd("wrong map border\n", STDERR);
	else if (msg == ERR_MLTPL_PLYR)
		ft_putstr_fd("multiple players\n", STDERR);
	else
		err_msg_nor(msg);
}
