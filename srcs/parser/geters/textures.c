/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 09:46:01 by wimam             #+#    #+#             */
/*   Updated: 2025/11/02 17:19:28 by wimam            ###   ########.fr       */
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

static char	*rm_new_line(char *str)
{
	int		i;
	int		len;
	char	*ret;

	len = ft_strlen(str);
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

bool	get_textures(t_cub *cub)
{
	char	**file;
	int		i;

	file = cub->parse.file;
	i = -1;
	while (file[++i] != NULL)
	{
		if (ft_memcmp(file[i], "NO ", 3) == 0)
			cub->parse.n_wall = rm_new_line(file[i] + 3);
		if (ft_memcmp(file[i], "SO ", 3) == 0)
			cub->parse.s_wall = rm_new_line(file[i] + 3);
		if (ft_memcmp(file[i], "WE ", 3) == 0)
			cub->parse.w_wall = rm_new_line(file[i] + 3);
		if (ft_memcmp(file[i], "EA ", 3) == 0)
			cub->parse.e_wall = rm_new_line(file[i] + 3);
		if (ft_memcmp(file[i], "F ", 2) == 0)
			cub->parse.floor_clr = rm_new_line(file[i] + 2);
		if (ft_memcmp(file[i], "C ", 2) == 0)
			cub->parse.sky_clr = rm_new_line(file[i] + 2);
	}
	return (texture_checker(cub));
}
