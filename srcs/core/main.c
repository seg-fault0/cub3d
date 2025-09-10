/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:02:37 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 21:05:08 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (err_msg(ERR_AC), 1);
	if (setup_cub(&cub, av) == false)
		return (1);
	luncher(&cub);
}
