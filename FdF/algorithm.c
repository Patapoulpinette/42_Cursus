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
#include "essai.h"

void	drawline(t_maps_params	*maps_params, t_mlx_params *mlx_params, t_algo_params *algo_params, int color)
{
	algo_params->x = maps_params->x0;
	algo_params->y = maps_params->y0;
	algo_params->dx = maps_params->x1 - maps_params->x0;
	algo_params->dy = maps_params->y1 - maps_params->y0;
	if (maps_params->x1 >= maps_params->y1)
	{
		algo_params->p = 2 * algo_params->dy - algo_params->dx;
		while (algo_params->x < maps_params->x1)
		{
			if (algo_params->p >= 0)
			{
				//dprintf(2, "if | x = %d | y = %d\n", algo_params->x, algo_params->y);
				mlx_pixel_put(mlx_params->mlx, mlx_params->window, algo_params->x, algo_params->y, color);
				algo_params->y = algo_params->y + 1;
				algo_params->p = algo_params->p + 2 * algo_params->dy - 2 * algo_params->dx;
			} else
			{
				//dprintf(2, "else | x = %d | y = %d\n", algo_params->x, algo_params->y);
				mlx_pixel_put(mlx_params->mlx, mlx_params->window, algo_params->x, algo_params->y, color);
				algo_params->p = algo_params->p + 2 * algo_params->dy;
			}
			algo_params->x = algo_params->x + 1;
		}
	}
	if (maps_params->x1 < maps_params->y1)
	{
		algo_params->p = 2 * algo_params->dx - algo_params->dy;
		while (algo_params->y < maps_params->y1)
		{
			if (algo_params->p >= 0)
			{
				//dprintf(2, "if | x = %d | y = %d\n", algo_params->x, algo_params->y);
				mlx_pixel_put(mlx_params->mlx, mlx_params->window, algo_params->x, algo_params->y, color);
				algo_params->x = algo_params->x + 1;
				algo_params->p = algo_params->p + 2 * algo_params->dx - 2 * algo_params->dy;
			} else
			{
				//dprintf(2, "else | x = %d | y = %d\n", algo_params->x, algo_params->y);
				mlx_pixel_put(mlx_params->mlx, mlx_params->window, algo_params->x, algo_params->y, color);
				algo_params->p = algo_params->p + 2 * algo_params->dx;
			}
			algo_params->y = algo_params->y + 1;
		}
	}
}
