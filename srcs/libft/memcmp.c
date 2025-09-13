/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 09:51:55 by wimam             #+#    #+#             */
/*   Updated: 2025/09/13 09:52:03 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*buffer1;
	const unsigned char	*buffer2;
	size_t				i;

	buffer1 = (const unsigned char *) s1;
	buffer2 = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (buffer1[i] != buffer2[i])
			return (buffer1[i] - buffer2[i]);
		i++;
	}
	return (0);
}
