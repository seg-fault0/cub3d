/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 22:02:44 by wimam             #+#    #+#             */
/*   Updated: 2025/09/08 23:52:24 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

// includes
# include "mlx.h"
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

// macros
# define WIN_HEIGHT 500
# define WIN_WITH 500

# define ESC_KEY 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100 

//structs
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}t_mlx;

typedef struct s_key
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	esq;
}t_key;

typedef struct s_cub
{
	t_mlx	mlx;
	t_key	key;
}t_cub;

//core
void	init_cub(t_cub *cub, int ac, char **av);
void	luncher(t_cub *cub);
int		ft_exit(t_cub *cub, int code);

//input
int		key_press(int key, t_key *keys);
int		key_release(int key, t_key *keys);
int		input_hander(t_cub *cub);

//mlx
bool	ft_mlx_init(t_mlx *mlx);

//libft
void	*ft_memset(void *b, int c, size_t len);

#endif