/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:29:24 by wimam             #+#    #+#             */
/*   Updated: 2025/09/08 22:30:14 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*buffer;

	i = 0;
	buffer = (char *) b;
	while (i < len)
	{
		buffer[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
