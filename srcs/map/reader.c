/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 03:03:59 by wimam             #+#    #+#             */
/*   Updated: 2025/09/09 03:30:36 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_map_size(char **av)
{
	char	*line;
	int		size;
	int		fd;

	fd = open (av[1], O_RDONLY);
	if (fd < 0)
		return (err_msg(ERR_OPEN), -1);
	size = 0;
	line = get_next_line(fd);
	while (line)
	{
		size++;
		if (size == MAX_MAP_SIZE)
			return (close (fd), free(line), err_msg(ERR_MAP_SIZE), -1);
		free(line);
		line = get_next_line(fd);
	}
	return (close (fd), size);
}

static char	**ft_read_map(char **av, int size)
{
	char	**map;
	int		i;
	int		fd;

	fd = open (av[1], O_RDONLY);
	if (fd < 0)
		return (err_msg(ERR_OPEN), NULL);
	map = malloc((size + 1) * sizeof(char *));
	if (!map)
		return (close (fd), err_msg(ERR_MALLOC), NULL);
	i = -1;
	while (++i < size)
		map[i] = get_next_line(fd);
	map[i] = NULL;
	return (close (fd), map);
}

char	**read_map(char **av)
{
	char	**map;
	int		map_size;

	map_size = get_map_size(av);
	if (map_size == -1)
		return (NULL);
	map = ft_read_map(av, map_size);
	return (map);
}
