/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:54:50 by wimam             #+#    #+#             */
/*   Updated: 2025/09/10 21:00:01 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_arr_size(char **arr)
{
	int	size;

	if (!arr)
		return (0);
	size = 0;
	while (arr[size])
		size++;
	return (size);
}

char	**get_2darr_cp(char **arr)
{
	char	**ret;
	int		size;
	int		i;

	size = get_arr_size(arr);
	ret = malloc((size + 1) * sizeof(char **));
	if (!ret)
		return (NULL);
	i = -1;
	while (arr[++i])
		ret[i] = ft_strdup(arr[i]);
	ret[i] = NULL;
	return (ret);
}

void	print_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		printf("%s\n", arr[i++]);
}

void	free2(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
