/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:48:00 by wimam             #+#    #+#             */
/*   Updated: 2025/11/01 18:06:09 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	check_clr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ',')
		return (false);
	while (str[i])
	{
		while (str[i] && ft_isdigit(str[i]))
			i++;
		if (str[i] && (str[i] == ',' && str[i + 1]))
			i++;
		if (str[i] && !ft_isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	check_clr_format(t_cub *cub)
{
	if (check_clr(cub->parse.sky_clr) == false
		|| check_clr(cub->parse.floor_clr) == false)
		return (err_msg(ERR_CLR_FORMAT), false);
	return (true);
}
