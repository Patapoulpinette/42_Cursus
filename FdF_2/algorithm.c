/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:02:13 by dbouron           #+#    #+#             */
/*   Updated: 2022/06/02 11:22:57 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawline_1(t_image *image, t_maps_coord *map, t_algo_params *algo, \
					int color)
{
	if (algo->dx >= 0)
	{
		algo->x = map->x0;
		algo->y = map->y0;
		algo->xe = map->x1;
	}
	else
	{
		algo->x = map->x1;
		algo->y = map->y1;
		algo->xe = map->x0;
	}
	my_img_pixel_put(image, algo->x, algo->y, color);
}

void	drawline_2(t_image *image, t_algo_params *algo, int color)
{
	while (algo->x < algo->xe)
	{
		algo->x = algo->x + 1;
		if (algo->px < 0)
			algo->px = algo->px + 2 * algo->dy1;
		else
		{
			if ((algo->dx < 0 && algo->dy < 0) \
					|| (algo->dx > 0 && algo->dy > 0))
				algo->y = algo->y + 1;
			else
				algo->y = algo->y - 1;
			algo->px = algo->px + 2 * (algo->dy1 - algo->dx1);
		}
		my_img_pixel_put(image, algo->x, algo->y, color);
	}
}

void	drawline_3(t_image *image, t_maps_coord *map, t_algo_params *algo, \
					int color)
{
	if (algo->dy >= 0)
	{
		algo->x = map->x0;
		algo->y = map->y0;
		algo->ye = map->y1;
	}
	else
	{
		algo->x = map->x1;
		algo->y = map->y1;
		algo->ye = map->y0;
	}
	my_img_pixel_put(image, algo->x, algo->y, color);
}

void	drawline_4(t_image *image, t_algo_params *algo, int color)
{
	while (algo->y < algo->ye)
	{
		algo->y = algo->y + 1;
		if (algo->py <= 0)
			algo->py = algo->py + 2 * algo->dx1;
		else
		{
			if ((algo->dx < 0 && algo->dy < 0) \
					|| (algo->dx > 0 && algo->dy > 0))
				algo->x = algo->x + 1;
			else
				algo->x = algo->x - 1;
			algo->py = algo->py + 2 * (algo->dx1 - algo->dy1);
		}
		my_img_pixel_put(image, algo->x, algo->y, color);
	}
}

void	bhm_line(t_image *image, t_maps_coord *map, int color)
{
	t_algo_params	algo;

	algo.dx = map->x1 - map->x0;
	algo.dy = map->y1 - map->y0;
	algo.dx1 = abs(algo.dx);
	algo.dy1 = abs(algo.dy);
	algo.px = 2 * algo.dy1 - algo.dx1;
	algo.py = 2 * algo.dx1 - algo.dy1;
	if (algo.dy1 <= algo.dx1)
	{
		drawline_1(image, map, &algo, color);
		drawline_2(image, &algo, color);
	}
	else
	{
		drawline_3(image, map, &algo, color);
		drawline_4(image, &algo, color);
	}
}
