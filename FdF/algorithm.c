/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:02:13 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/21 15:06:18 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//#include "essai.h"

void drawline(t_image *image, int x0, int y0, int x1, int y1, int color)
{
	t_algo_params	algo_params;

	algo_params.x = x0;
	algo_params.y = y0;
	algo_params.dx = x1 - x0;
	algo_params.dy = y1 - y0;
	if (x1 >= y1)
	{
		algo_params.p = 2 * algo_params.dy - algo_params.dx;
		while (algo_params.x < x1)
		{
			if (algo_params.p >= 0)
			{
				//dprintf(2, "if | x = %d | y = %d\n", algo_params.x, algo_params.y);
				my_mlx_pixel_put(image, algo_params.x, algo_params.y, color);
				algo_params.y = algo_params.y + 1;
				algo_params.p = algo_params.p + 2 * algo_params.dy - 2 * algo_params.dx;
			} else
			{
				//dprintf(2, "else | x = %d | y = %d\n", algo_params.x, algo_params.y);
				my_mlx_pixel_put(image, algo_params.x, algo_params.y, color);
				algo_params.p = algo_params.p + 2 * algo_params.dy;
			}
			algo_params.x = algo_params.x + 1;
		}
	}
	if (x1 < y1)
	{
		algo_params.p = 2 * algo_params.dx - algo_params.dy;
		while (algo_params.y < y1)
		{
			if (algo_params.p >= 0)
			{
				//dprintf(2, "if | x = %d | y = %d\n", algo_params.x, algo_params.y);
				my_mlx_pixel_put(image, algo_params.x, algo_params.y, color);
				algo_params.x = algo_params.x + 1;
				algo_params.p = algo_params.p + 2 * algo_params.dx - 2 * algo_params.dy;
			} else
			{
				//dprintf(2, "else | x = %d | y = %d\n", algo_params.x, algo_params.y);
				my_mlx_pixel_put(image, algo_params.x, algo_params.y, color);
				algo_params.p = algo_params.p + 2 * algo_params.dx;
			}
			algo_params.y = algo_params.y + 1;
		}
	}
}
