/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:03:34 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/31 11:47:24 by dbouron          ###   ########.fr       */
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

	if ((x < 0 || y < 0) || (x > image->x_img || y > image->y_img))
		return ;
	dst = image->addr + (y * image->size_line + x
			* (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_in_image(t_image *image, t_maps_coord *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->y_len - 1)
	{
		i = 0;
		while (i < map->x_len - 1)
		{
			map->x0 = i * ZOOM;
			map->y0 = j * ZOOM;
			iso(image, &map->x0, &map->y0, map->map_tab[j][i]);
			map->x1 = (i + 1) * ZOOM;
			map->y1 = j * ZOOM;
			iso(image, &map->x1, &map->y1, map->map_tab[j][i + 1]);
			bhm_line(image, map, 0xffb703);
			map->x1 = i * ZOOM;
			map->y1 = (j + 1) * ZOOM;
			iso(image, &map->x1, &map->y1, map->map_tab[j + 1][i]);
			bhm_line(image, map, 0xffb703);
			i++;
		}
		j++;
	}
}

int	exit_program(void)
{
	dprintf(2, "exit with mouse\n");
	exit(0);
}

void	display_window(t_maps_coord *map)
{
	t_mlx_params	mlx;
	t_image			image;

	mlx.x_win = map->x_len * X_WIN_COEF;
	mlx.y_win = map->y_len * Y_WIN_COEF;
	image.x_img = map->x_len * X_WIN_COEF;
	image.y_img = map->y_len * Y_WIN_COEF;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, mlx.x_win,
			mlx.y_win, "New window");
	dprintf(2, "xlen = %d, ylen = %d\n", map->x_len, map->y_len);//for testing
	dprintf(2, "xwin = %d, ywin = %d\n", mlx.x_win, mlx.y_win);//for testing
	//create a new image
	image.img = mlx_new_image(mlx.mlx, image.x_img, image.y_img);
	dprintf(2, "ximg = %d, yimg = %d\n", image.x_img, image.y_img);//for testing
	//give image address
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.size_line, &image.endian);
	//draw pixel in image
	draw_in_image(&image, map);
	//put image to window
	mlx_put_image_to_window(mlx.mlx, mlx.window, image.img, 0, 0);
	//do something when pressing key in a window
	mlx_key_hook(mlx.window, press_key, &mlx);
	//do something when pressing mouse button
	mlx_hook(mlx.window, 17, 1L << 5, exit_program, (void *)0);
	mlx_loop(mlx.mlx);
}
