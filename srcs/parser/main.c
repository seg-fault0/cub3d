/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:20:52 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 20:56:37 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	map_init(t_cub *cub, char *path)
{
	cub->parse.map = read_map(path);
	if (!cub->parse.map)
		return (false);
	cub->parse.max_map_y = get_arr_size(cub->parse.map);
	return (true);
}
