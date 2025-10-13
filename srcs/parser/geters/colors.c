/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:07:17 by wimam             #+#    #+#             */
/*   Updated: 2025/09/13 11:14:15 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_clr(const char *str)
{
	int		r;
	int		g;
	int		b;
	char	*ptr;

	r = (int)strtol(str, &ptr, 10);
	if (*ptr != ',')
		return (-1);
	ptr++;
	g = (int)strtol(ptr, &ptr, 10);
	if (*ptr != ',')
		return (-1);
	ptr++;
	b = (int)strtol(ptr, &ptr, 10);
	if (*ptr != '\0')
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

bool	get_clr_format(t_cub *cub)
{
	cub->clr.floor = get_clr(cub->parse.floor_clr);
	cub->clr.sky = get_clr(cub->parse.sky_clr);
	if (cub->clr.floor == -1
		|| cub->clr.sky == -1)
		return (err_msg(ERR_CLR_FORMAT), false);
	return (true);
}
