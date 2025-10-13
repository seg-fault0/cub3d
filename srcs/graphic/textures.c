/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:44:03 by wimam             #+#    #+#             */
/*   Updated: 2025/10/13 14:33:23 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	*load_tex(t_img *img)
{
	int		*buffer;
	int		x;
	int		y;
	int		pixel;

	if (!img || !img->addr)
		return (NULL);
	buffer = malloc(sizeof(int) * img->width * img->height);
	if (!buffer)
		return (err_msg(ERR_MALLOC), NULL);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pixel = *(int *)(img->addr
					+ (y * img->size_line + x * (img->bpp / 8)));
			buffer[y * img->width + x] = pixel;
			x++;
		}
		y++;
	}
	return (buffer);
}

int	*load_tex_animation(t_img demon[DEMON_NBR])
{
	static int	i;
	static int	*buffer;

	if (i == DEMON_NBR)
		i = 0;
	free(buffer);
	buffer = load_tex(&demon[i]);
	i++;
	return (buffer);
}

bool	texture_loader(t_cub *cub)
{
	int	i;

	cub->textures[0] = load_tex(&cub->img.n_wall);
	cub->textures[1] = load_tex(&cub->img.s_wall);
	cub->textures[2] = load_tex(&cub->img.e_wall);
	cub->textures[3] = load_tex(&cub->img.w_wall);
	cub->textures[4] = load_tex(&cub->img.door);
	cub->textures[5] = load_tex_animation(cub->img.demon);
	i = -1;
	while (++i < TEXTURE_NBR)
	{
		if (!cub->textures[i])
			return (false);
	}
	return (true);
}
