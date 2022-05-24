/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:03:34 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/25 01:12:02 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	press_key(int key, t_mlx_params *mlx_params)
{
	if (key == 8)
		mlx_clear_window(mlx_params->mlx, mlx_params->window);
	else if (key == 53)
	{
		mlx_destroy_window(mlx_params->mlx, mlx_params->window);
		dprintf(2, "exit with ESC\n");
		exit(0);
	}
	else
		dprintf(2, "key number : %d\n", key);
	return (0);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->size_line + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	exit_program(void)
{
	dprintf(2, "exit with mouse\n");
	exit(0);
}

void	display_window(void)
{
	t_mlx_params	mlx_params;
	t_image			image;
//	t_maps_coord	maps_coord;
//	t_algo_params	algo_params;

	mlx_params.x_win = 1500;
	mlx_params.y_win = 1200;
	mlx_params.mlx = mlx_init();
	mlx_params.window = mlx_new_window(mlx_params.mlx, mlx_params.x_win, mlx_params.y_win, "New window");
	//create a new image and draw map into
	image.img = mlx_new_image(mlx_params.mlx, mlx_params.x_win, mlx_params.y_win);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.size_line, &image.endian);
	my_mlx_pixel_put(&image, 50, 50, 0x00FF0000);
	mlx_put_image_to_window(mlx_params.mlx, mlx_params.window, image.img, 0, 0);
	//do something when pressing key in a window
	mlx_key_hook(mlx_params.window, press_key, &mlx_params);
	//do something when pressing mouse button
	mlx_hook(mlx_params.window, 17, 1L << 5, exit_program, (void *)0);
	mlx_loop(mlx_params.mlx);
}
