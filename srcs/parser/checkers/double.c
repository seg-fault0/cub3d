/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:13:30 by wimam             #+#    #+#             */
/*   Updated: 2025/11/01 17:35:40 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_flag_bit(char *str)
{
	if (ft_memcmp(str, "NO", 2) == 0)
		return (0);
	else if (ft_memcmp(str, "SO", 2) == 0)
		return (1);
	else if (ft_memcmp(str, "WE", 2) == 0)
		return (2);
	else if (ft_memcmp(str, "EA", 2) == 0)
		return (3);
	else if (ft_memcmp(str, "F", 1) == 0)
		return (4);
	else if (ft_memcmp(str, "C", 1) == 0)
		return (5);
	else
		return (-1);
}

bool	check_double_textures(t_cub *cub)
{
	int	flag;
	int	flag_bit;
	int	i;

	i = 0;
	flag = 0;
	while (cub->parse.file[i])
	{
		flag_bit = get_flag_bit(cub->parse.file[i]);
		if (flag_bit != -1)
		{
			if ((flag >> flag_bit) & 1)
				return (err_msg(ERR_DOUBLE), false);
			flag |= (1 << flag_bit);
		}
		i++;
	}
	return (true);
}
