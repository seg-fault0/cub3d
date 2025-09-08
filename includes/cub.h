/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:02:44 by wimam             #+#    #+#             */
/*   Updated: 2025/09/08 22:40:11 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

// includes
# include "mlx.h"
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

// macros
# define WIN_HEIGHT 500
# define WIN_WITH 500

//structs
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}t_mlx;

typedef struct s_cub
{
	t_mlx	mlx;
}t_cub;

//core
void	ft_exit(t_cub *cub, int code);
void	init_cub(t_cub *cub, int ac, char **av);

//mlx
bool	ft_mlx_init(t_mlx *mlx);

//libft
void	*ft_memset(void *b, int c, size_t len);

#endif