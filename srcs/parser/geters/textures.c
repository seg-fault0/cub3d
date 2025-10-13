/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 09:46:01 by wimam             #+#    #+#             */
/*   Updated: 2025/09/13 11:06:24 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	texture_checker(t_cub *cub)
{
	if (!cub->parse.n_wall
		|| !cub->parse.s_wall
		|| !cub->parse.e_wall
		|| !cub->parse.w_wall
		|| !cub->parse.sky_clr
		|| !cub->parse.floor_clr)
		return (err_msg(ERR_ELMT_NF), false);
	return (true);
}

static char	*skip_spaces(char	*str)
{
	char	*p;

	while (*str && *str == ' ')
		str++;
	p = ft_strdup(str);
	p[ft_strlen(p) - 1] = '\0';
	return (p);
}

bool	get_textures(t_cub *cub)
{
	char	**file;
	int		i;

	file = cub->parse.file;
	i = -1;
	while (file[++i] != NULL)
	{
		if (ft_memcmp(file[i], "NO", 2) == 0)
			cub->parse.n_wall = skip_spaces(file[i] + 2);
		if (ft_memcmp(file[i], "SO", 2) == 0)
			cub->parse.s_wall = skip_spaces(file[i] + 2);
		if (ft_memcmp(file[i], "WE", 2) == 0)
			cub->parse.w_wall = skip_spaces(file[i] + 2);
		if (ft_memcmp(file[i], "EA", 2) == 0)
			cub->parse.e_wall = skip_spaces(file[i] + 2);
		if (ft_memcmp(file[i], "F", 1) == 0)
			cub->parse.floor_clr = skip_spaces(file[i] + 1);
		if (ft_memcmp(file[i], "C", 1) == 0)
			cub->parse.sky_clr = skip_spaces(file[i] + 1);
	}
	return (texture_checker(cub));
}
