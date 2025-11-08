/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:07:17 by wimam             #+#    #+#             */
/*   Updated: 2025/11/08 20:35:01 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static const char	*skip_to_next(const char *s, char c)
{
	while (*s && *s != c)
		s++;
	return (s);
}

static int	get_clr(const char *str)
{
	int				r;
	int				g;
	int				b;
	const char		*ptr;

	r = atoi(str);
	ptr = skip_to_next(str, ',');
	if (*ptr != ',')
		return (-1);
	ptr++;
	g = atoi(ptr);
	ptr = skip_to_next(ptr, ',');
	if (*ptr != ',')
		return (-1);
	ptr++;
	b = atoi(ptr);
	ptr = skip_to_next(ptr, '\0');
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
