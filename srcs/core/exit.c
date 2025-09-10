/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:27:10 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 09:34:38 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

int	ft_exit(t_cub *cub, int code)
{
	free_map(cub->map);
	free_img(cub);
	free_mlx(cub->mlx);
	exit(code);
	return (0);
}
