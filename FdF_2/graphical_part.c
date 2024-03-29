/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:03:34 by dbouron           #+#    #+#             */
/*   Updated: 2022/06/03 18:50:35 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_image(t_mlx_params *mlx, t_image *image)
{
	image->x_img = mlx->x_win;
	image->y_img = mlx->y_win;
	image->img = mlx_new_image(mlx->mlx, image->x_img, image->y_img);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->size_line, &image->endian);
}

void	init_coeff_values(t_maps_coord *map, t_image *image)
{
	image->zoom = (X_RESOLUTION / map->x_len / 4);
	image->x_translation = (image->x_img / 2);
	image->y_translation = (image->y_img / 8);
	image->z_multiplicator = 3;
	image->angle = 0.46373398;
}

int	press_key(int key, t_structs *structs)
{
	if (key == 8)
		mlx_clear_window(structs->mlx->mlx, structs->mlx->window);
	else if (key == 53)
	{
		mlx_destroy_window(structs->mlx->mlx, structs->mlx->window);
		exit(EXIT_SUCCESS);
	}
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		translation(key, structs);
	else if (key == 69 || key == 78)
		zoom(key, structs);
	else if (key == 24 || key == 27)
		change_height(key, structs);
	else if (key == 15 || key == 37)
		rotate(key, structs);
	else
		dprintf(2, "key number : %d\n", key);
	return (0);
}

int	exit_program(void)
{
	exit(EXIT_SUCCESS);
}

void	display_window(t_maps_coord *map)
{
	t_mlx_params	mlx;
	t_image			image;
	t_structs		structs;

	structs.mlx = &mlx;
	structs.image = &image;
	structs.map = map;
	mlx.x_win = map->x_len * (X_RESOLUTION / map->x_len / 2);
	mlx.y_win = map->y_len * (Y_RESOLUTION / map->y_len / 2);
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, mlx.x_win,
			mlx.y_win, map->name);
	create_image(&mlx, &image);
	init_coeff_values(map, &image);
	draw_in_image(&image, map);
	mlx_put_image_to_window(mlx.mlx, mlx.window, image.img, 0, 0);
	mlx_destroy_image(mlx.mlx, image.img);
	mlx_key_hook(mlx.window, press_key, &structs);
	mlx_hook(mlx.window, 17, 1L << 5, exit_program, (void *)0);
	mlx_loop(mlx.mlx);
}
