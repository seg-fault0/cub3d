/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:20:52 by wimam             #+#    #+#             */
/*   Updated: 2025/10/13 11:58:04 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	parse(t_cub *cub, char *path)
{
	if (read_file(cub, path) == false
		|| get_textures(cub) == false
		|| get_map(cub) == false
		|| get_clr_format(cub) == false)
		return (false);
	if (check_map_border(cub) == false
		|| check_repeated_map_chars(cub) == false)
		return (false);
	return (true);
}
