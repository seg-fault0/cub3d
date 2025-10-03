#include "cub.h"

void	init_img(t_cub *cub, void **img, char **addr, int width, int height)
{
	*img = mlx_new_image(cub->mlx.mlx, width, height);
	if (*img == NULL)
		clean_exit(cub, 1);
	*addr = mlx_get_data_addr(*img, &cub->img.bits_per_pixel,
			&cub->img.size_line, &cub->img.endian);
}
