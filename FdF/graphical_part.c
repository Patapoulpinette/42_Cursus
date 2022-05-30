/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:03:34 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/30 11:55:26 by dbouron          ###   ########.fr       */
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

	if ((x < 0 || y < 0) || (x > image->x_img || y > image->y_img))
		return ;
	dst = image->addr + (y * image->size_line + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_in_image(t_image *image, t_maps_coord *maps_coord)
{
	int	i;
	int	j;

	j = 0;
	while (j < maps_coord->y_len - 1)
	{
		i = 0;
		while (i < maps_coord->x_len - 1)
		{
//			dprintf(2, "test : %d ; %d\n", i, j);//for testing
			maps_coord->x0 = i * ZOOM;
			maps_coord->y0 = j * ZOOM;
			iso(image, &maps_coord->x0, &maps_coord->y0, Z_MULT * maps_coord->map_tab[j][i]);
//			dprintf(2, "x0 = %d | y0 = %d\n", maps_coord->x0, maps_coord->y0);
			my_mlx_pixel_put(image, maps_coord->x0, maps_coord->y0, 0xfdffb6);
			maps_coord->x1 = (i + 1) * ZOOM;
			maps_coord->y1 = j * ZOOM;
			iso(image, &maps_coord->x1, &maps_coord->y1, Z_MULT * maps_coord->map_tab[j][i + 1]);
			bhm_line(image, maps_coord, 0x6a040f);
			maps_coord->x1 = i * ZOOM;
			maps_coord->y1 = (j + 1) * ZOOM;
			iso(image, &maps_coord->x1, &maps_coord->y1, Z_MULT * maps_coord->map_tab[j + 1][i]);
			bhm_line(image, maps_coord, 0x6a040f);
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

void	display_window(t_maps_coord *maps_coord)
{
	t_mlx_params	mlx_params;
	t_image			image;

	mlx_params.x_win = maps_coord->x_len * WIN_COEF;
	mlx_params.y_win = maps_coord->y_len * WIN_COEF;
	image.x_img = maps_coord->x_len * WIN_COEF;
	image.y_img = maps_coord->y_len * WIN_COEF;
	mlx_params.mlx = mlx_init();
	mlx_params.window = mlx_new_window(mlx_params.mlx, mlx_params.x_win,
			mlx_params.y_win, "New window");
	dprintf(2, "xwin = %d, ywin = %d\n", mlx_params.x_win, mlx_params.y_win);//for testing
	//create a new image
	image.img = mlx_new_image(mlx_params.mlx, image.x_img, image.y_img);
	dprintf(2, "ximg = %d, yimg = %d\n", image.x_img, image.y_img);//for testing
	//give image address
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.size_line, &image.endian);
	//draw pixel in image
	draw_in_image(&image, maps_coord);
	//put image to window
	mlx_put_image_to_window(mlx_params.mlx, mlx_params.window, image.img, 0, 0);
	//do something when pressing key in a window
	mlx_key_hook(mlx_params.window, press_key, &mlx_params);
	//do something when pressing mouse button
	mlx_hook(mlx_params.window, 17, 1L << 5, exit_program, (void *)0);
	mlx_loop(mlx_params.mlx);
}
