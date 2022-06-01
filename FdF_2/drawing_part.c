/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:43:02 by dbouron           #+#    #+#             */
/*   Updated: 2022/06/01 18:57:34 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_image *image, int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(ANGLE)
		+ ((float)image->x_img / 2);
	*y = -z * Z_MULT + (previous_x + previous_y) * sin(ANGLE)
		+ ((float)image->y_img / 8);
}

void	draw_last_line(t_image *image, t_maps_coord *map)
{
	int	i;
	int	j;

	i = map->x_len - 1;
	j = 0;
	while (j < map->y_len - 1)
	{
		map->x0 = i * (X_RESOLUTION / map->x_len / 4);
		map->y0 = j * (X_RESOLUTION / map->x_len / 4);
		iso(image, &map->x0, &map->y0, map->map_tab[j][i]);
		map->x1 = i * (X_RESOLUTION / map->x_len / 4);
		map->y1 = (j + 1) * (X_RESOLUTION / map->x_len / 4);
		iso(image, &map->x1, &map->y1, map->map_tab[j + 1][i]);
		bhm_line(image, map, COLOR_2);
		j++;
	}
	i = 0;
	j = map->y_len - 1;
	while (i < map->x_len - 1)
	{
		map->x0 = i * (X_RESOLUTION / map->x_len / 4);
		map->y0 = j * (X_RESOLUTION / map->x_len / 4);
		iso(image, &map->x0, &map->y0, map->map_tab[j][i]);
		map->x1 = (i + 1) * (X_RESOLUTION / map->x_len / 4);
		map->y1 = j * (X_RESOLUTION / map->x_len / 4);
		iso(image, &map->x1, &map->y1, map->map_tab[j][i + 1]);
		bhm_line(image, map, COLOR_1);
		i++;
	}
}

void	my_img_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= image->x_img || y >= image->y_img)
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
			map->x0 = i * (X_RESOLUTION / map->x_len / 4);
			map->y0 = j * (X_RESOLUTION / map->x_len / 4);
			iso(image, &map->x0, &map->y0, map->map_tab[j][i]);
			map->x1 = (i + 1) * (X_RESOLUTION / map->x_len / 4);
			map->y1 = j * (X_RESOLUTION / map->x_len / 4);
			iso(image, &map->x1, &map->y1, map->map_tab[j][i + 1]);
			bhm_line(image, map, COLOR_1);
			map->x1 = i * (X_RESOLUTION / map->x_len / 4);
			map->y1 = (j + 1) * (X_RESOLUTION / map->x_len / 4);
			iso(image, &map->x1, &map->y1, map->map_tab[j + 1][i]);
			bhm_line(image, map, COLOR_2);
			i++;
		}
		j++;
	}
	draw_last_line(image, map);
}
