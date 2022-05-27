/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:02:13 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/27 18:00:26 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	bhm_line(t_image *image, t_maps_coord *maps_coord, int color)
{
	t_algo_params	algo;

	algo.dx = maps_coord->x1 - maps_coord->x0;
	algo.dy = maps_coord->y1 - maps_coord->y0;
	algo.dx1 = abs(algo.dx);
	algo.dy1 = abs(algo.dy);
	algo.px = 2 * algo.dy1 - algo.dx1;
	algo.py = 2 * algo.dx1 - algo.dy1;
	if (algo.dy1 <= algo.dx1)
	{
		if (algo.dx >= 0)
		{
			algo.x = maps_coord->x0;
			algo.y = maps_coord->y0;
			algo.xe = maps_coord->x1;
		}
		else
		{
			algo.x = maps_coord->x1;
			algo.y = maps_coord->y1;
			algo.xe = maps_coord->x0;
		}
		my_mlx_pixel_put(image, maps_coord, algo.x, algo.y, color);
		while (algo.x < algo.xe)
		{
			algo.x = algo.x + 1;
			if (algo.px < 0)
			{
				algo.px = algo.px + 2 * algo.dy1;
			}
			else
			{
				if ((algo.dx < 0 && algo.dy < 0) || (algo.dx > 0 && algo.dy > 0))
				{
					algo.y = algo.y + 1;
				}
				else
				{
					algo.y = algo.y - 1;
				}
				algo.px = algo.px + 2 * (algo.dy1 - algo.dx1);
			}
			my_mlx_pixel_put(image, maps_coord, algo.x, algo.y, color);
		}
	}
	else
	{
		if (algo.dy >= 0)
		{
			algo.x = maps_coord->x0;
			algo.y = maps_coord->y0;
			algo.ye = maps_coord->y1;
		}
		else
		{
			algo.x = maps_coord->x1;
			algo.y = maps_coord->y1;
			algo.ye = maps_coord->y0;
		}
		my_mlx_pixel_put(image, maps_coord, algo.x, algo.y, color);
		while (algo.y < algo.ye)
		{
			algo.y = algo.y + 1;
			if (algo.py <= 0)
			{
				algo.py = algo.py + 2 * algo.dx1;
			}
			else
			{
				if ((algo.dx < 0 && algo.dy < 0) || (algo.dx > 0 && algo.dy > 0))
				{
					algo.x = algo.x + 1;
				}
				else
				{
					algo.x = algo.x - 1;
				}
				algo.py = algo.py + 2 * (algo.dx1 - algo.dy1);
			}
			my_mlx_pixel_put(image, maps_coord, algo.x, algo.y, color);
		}
	}
}
