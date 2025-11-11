/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 03:03:59 by wimam             #+#    #+#             */
/*   Updated: 2025/11/11 14:00:47 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_file_size(char *path)
{
	char	*line;
	int		size;
	int		fd;

	fd = open (path, O_RDONLY);
	if (fd < 0)
		return (err_msg(ERR_OPEN), -1);
	size = 0;
	line = get_next_line(fd);
	while (line)
	{
		size++;
		if (size == MAX_FILE_SIZE)
			return (close (fd), free(line), err_msg(ERR_MAP_SIZE), -1);
		free(line);
		line = get_next_line(fd);
	}
	return (close (fd), size);
}

static char	**ft_read_file(char *path, int size)
{
	char	**map;
	int		i;
	int		fd;

	fd = open (path, O_RDONLY);
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

bool	read_file(t_cub *cub, char *path)
{
	int		map_size;

	if (check_map_extension(path) == false)
		return (err_msg(ERR_MAP_EXT), false);
	map_size = get_file_size(path);
	if (map_size == -1)
		return (false);
	cub->parse.file = ft_read_file(path, map_size);
	if (check_file(cub->parse.file) == false)
		return (err_msg(ERR_BAD_FILE), false);
	return (true);
}
