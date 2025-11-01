/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 08:20:52 by wimam             #+#    #+#             */
/*   Updated: 2025/11/01 17:37:13 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	allowed_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '1' || c == '0' || c == 'D' || c == 'B'
		|| c == 'C' || c == 'O')
		return (true);
	return (false);
}

bool	parse(t_cub *cub, char *path)
{
	if (read_file(cub, path) == false
		|| get_textures(cub) == false
		|| get_map(cub) == false
		|| get_clr_format(cub) == false)
		return (false);
	if (check_map_border(cub) == false
		|| check_double_player(cub) == false
		|| check_double_textures(cub) == false)
		return (false);
	return (true);
}
