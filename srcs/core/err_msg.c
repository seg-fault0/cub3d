/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 00:29:43 by wimam             #+#    #+#             */
/*   Updated: 2025/09/09 00:40:16 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define STDERR 2

void	err_msg(int msg)
{
	ft_putstr_fd("ERR : ", STDERR);
	if (msg == ERR_MALLOC)
		ft_putstr_fd("ALLOCATION FAILED\n", STDERR);
	else if (msg == ERR_MLX)
		ft_putstr_fd("MLX FAILED\n", STDERR);
	else if (msg == ERR_WIN)
		ft_putstr_fd("WINDOW FAILED\n", STDERR);
}
