/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:44:03 by wimam             #+#    #+#             */
/*   Updated: 2025/10/12 15:26:02 by wimam            ###   ########.fr       */
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
			pixel = *(int *)(img->addr + (y * img->size_line + x * (img->bpp / 8)));
			buffer[y * img->width + x] = pixel;
			x++;
		}
		y++;
	}
	return (buffer);
}

bool	texture_loader(t_cub *cub)
{
	cub->textures[0] = load_tex(&cub->img.mm_frame);
	cub->textures[1] = load_tex(&cub->img.mm_wall);
	cub->textures[2] = load_tex(&cub->img.mm_floor);
	cub->textures[3] = load_tex(&cub->img.n_wall);
	cub->textures[4] = load_tex(&cub->img.s_wall);
	cub->textures[5] = load_tex(&cub->img.e_wall);
	cub->textures[6] = load_tex(&cub->img.e_wall);
	if (!cub->textures[0] || !cub->textures[1] || !cub->textures[2]
		|| !cub->textures[3] || !cub->textures[4] || !cub->textures[5]
		|| !cub->textures[6])
		return (false);
	return (true);
}
