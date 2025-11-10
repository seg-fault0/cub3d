/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:07:16 by wimam             #+#    #+#             */
/*   Updated: 2025/11/10 18:18:54 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	size_t	x;

	if (count == 0 || size == 0)
		return (malloc(0));
	x = count * size;
	if (x / count != size || x / size != count)
		return (NULL);
	buffer = malloc(x);
	if (!buffer)
		return (NULL);
	ft_memset(buffer, 0, x);
	return (buffer);
}
