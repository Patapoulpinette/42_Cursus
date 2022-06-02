/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:03:34 by dbouron           #+#    #+#             */
/*   Updated: 2022/06/01 18:49:54 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	press_key(int key, t_mlx_params *mlx)
{
	if (key == 8)
		mlx_clear_window(mlx->mlx, mlx->window);
	else if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		exit(0);
	}
	else
		dprintf(2, "key number : %d\n", key);
	return (0);
}

int	exit_program(void)
{
	exit(0);
}

void	display_window(t_maps_coord *map)
{
	t_mlx_params	mlx;
	t_image			image;

	mlx.x_win = map->x_len * (X_RESOLUTION / map->x_len / 2);
	mlx.y_win = map->y_len * (Y_RESOLUTION / map->y_len / 2);
	image.x_img = map->x_len * (X_RESOLUTION / map->x_len / 2);
	image.y_img = map->y_len * (Y_RESOLUTION / map->y_len / 2);
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, mlx.x_win,
			mlx.y_win, map->name);
	image.img = mlx_new_image(mlx.mlx, image.x_img, image.y_img);
	dprintf(2, "xlen = %d, ylen = %d | xwin = %d, ywin = %d | ximg = %d, yimg = %d\n", map->x_len, map->y_len, mlx.x_win, mlx.y_win, image.x_img, image.y_img);//for testing
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.size_line, &image.endian);
	draw_in_image(&image, map);
	mlx_put_image_to_window(mlx.mlx, mlx.window, image.img, 0, 0);
	mlx_key_hook(mlx.window, press_key, &mlx);
	mlx_hook(mlx.window, 17, 1L << 5, exit_program, (void *)0);
	mlx_loop(mlx.mlx);
}
