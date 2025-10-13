/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 09:37:14 by wimam             #+#    #+#             */
/*   Updated: 2025/10/13 15:53:30 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	minimap(t_cub *cub)
{
	draw_img_to_img(&cub->img.display, &cub->img.mm_floor, 10, 6);
	minimap_rays(cub);
	draw_walls(cub);
	draw_img_to_img(&cub->img.display, &cub->img.mm_frame, 10, 6);
}
