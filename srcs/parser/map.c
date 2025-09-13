/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 09:30:36 by wimam             #+#    #+#             */
/*   Updated: 2025/09/13 09:38:24 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	get_map(t_cub *cub)
{
	int	cur_i;

	cur_i = cub->parse.cur_i;
	cub->parse.map = get_2darr_cp(&cub->parse.all[cur_i]);
	return (true);
}
