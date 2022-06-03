/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:06:35 by dbouron           #+#    #+#             */
/*   Updated: 2022/06/03 17:42:36 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translation(int key, t_structs *structs)
{
	mlx_clear_window(structs->mlx->mlx, structs->mlx->window);
	create_image(structs->mlx, structs->image);
	if (key == 123)
		structs->image->x_translation -= 10;
	else if (key == 124)
		structs->image->x_translation += 10;
	else if (key == 125)
		structs->image->y_translation += 10;
	else if (key == 126)
		structs->image->y_translation -= 10;
	draw_in_image(structs->image, structs->map);
	mlx_put_image_to_window(structs->mlx->mlx, structs->mlx->window, \
		structs->image->img, 0, 0);
}

void	zoom(int key, t_structs *structs)
{
	mlx_clear_window(structs->mlx->mlx, structs->mlx->window);
	create_image(structs->mlx, structs->image);
	if (key == 69)
		structs->image->zoom += 1;
	else if (key == 78)
		structs->image->zoom -= 1;
	draw_in_image(structs->image, structs->map);
	mlx_put_image_to_window(structs->mlx->mlx, structs->mlx->window, \
		structs->image->img, 0, 0);
}

void	change_height(int key, t_structs *structs)
{
	mlx_clear_window(structs->mlx->mlx, structs->mlx->window);
	create_image(structs->mlx, structs->image);
	if (key == 24)
		structs->image->z_multiplicator += 1;
	else if (key == 27)
		structs->image->z_multiplicator -= 1;
	draw_in_image(structs->image, structs->map);
	mlx_put_image_to_window(structs->mlx->mlx, structs->mlx->window, \
		structs->image->img, 0, 0);
}

void	rotate(int key, t_structs *structs)
{
	mlx_clear_window(structs->mlx->mlx, structs->mlx->window);
	create_image(structs->mlx, structs->image);
	if (key == 15)
		structs->image->angle += 0.01;
	else if (key == 37)
		structs->image->angle -= 0.01;
	draw_in_image(structs->image, structs->map);
	mlx_put_image_to_window(structs->mlx->mlx, structs->mlx->window, \
		structs->image->img, 0, 0);
}
