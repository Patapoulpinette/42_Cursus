/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:02:13 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/05 15:38:58 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawline(t_maps_params	*maps_params, t_mlx_params *mlx_params, int color)
{
	int	dx;
	int	dy;
	int	p;
	int	x;
	int	y;

	dx = maps_params->x1 - maps_params->x0;
	dy = maps_params->y1 - maps_params->y0;
	x = maps_params->x0;
	y = maps_params->y0;
	p = 2 * dy - dx;
	while (x < maps_params->x1)
	{
		if (p >= 0)
		{
			mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, color);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, color);
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}
