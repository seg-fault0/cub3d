/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:27:10 by wimam             #+#    #+#             */
/*   Updated: 2025/10/14 20:29:25 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_loaded_textures(int *textures[])
{
	int	i;

	i = -1;
	while (++i < TEXTURE_NBR)
		free(textures[i]);
}

void	free_sprite(t_cub *cub)
{
	if (cub->sprites.sprites)
		free(cub->sprites.sprites);
	if (cub->sprites.zbuffer)
		free(cub->sprites.zbuffer);
	if (cub->sprites.order)
		free(cub->sprites.order);
	if (cub->sprites.distance)
		free(cub->sprites.distance);
}

int	ft_exit(t_cub *cub, int code)
{
	free_loaded_textures(cub->textures);
	free_animation(cub->mlx.mlx, cub->img.demon);
	// free_sprite(cub);
	free2(cub->parse.file);
	free2(cub->parse.map);
	free(cub->parse.n_wall);
	free(cub->parse.s_wall);
	free(cub->parse.e_wall);
	free(cub->parse.w_wall);
	free(cub->parse.sky_clr);
	free(cub->parse.floor_clr);
	free_img(cub);
	free_mlx(cub->mlx);
	exit(code);
	return (0);
}
