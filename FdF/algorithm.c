/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:02:13 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/06 12:10:23 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//void	drawline(t_maps_params	*maps_params, t_mlx_params *mlx_params, int color)
//{
//	int	dx;
//	int	dy;
//	int	p;
//	int	x;
//	int	y;
//
//	dx = maps_params->x1 - maps_params->x0;
//	dy = maps_params->y1 - maps_params->y0;
//	x = maps_params->x0;
//	y = maps_params->y0;
//	p = 2 * dy - dx;
//	while (x < maps_params->x1)
//	{
//		if (p >= 0)
//		{
//			mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, color);
//			y = y + 1;
//			p = p + 2 * dy - 2 * dx;
//		}
//		else
//		{
//			mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, color);
//			p = p + 2 * dy;
//		}
//		x = x + 1;
//	}
//}


//------------------------------------------------------------------------------


void	drawline(t_maps_params	*maps_params, t_mlx_params *mlx_params, t_algo_params *algo_params, int color)
{
	algo_params->x = maps_params->x0;
	algo_params->y = maps_params->y0;
	algo_params->dx = maps_params->x1 - maps_params->x0;
	algo_params->dy = maps_params->y1 - maps_params->y0;
	algo_params->m = algo_params->dy / algo_params->dx;
	algo_params->p = 2 * algo_params->dy - algo_params->dx;
	if (algo_params->m < 1)
	{
		while (algo_params->x < maps_params->x1)
		{
			if (algo_params->p >= 0)
			{
				mlx_pixel_put(mlx_params->mlx, mlx_params->window, algo_params->x, algo_params->y, color);
				algo_params->y = algo_params->y + 1;
				algo_params->p = algo_params->p + 2 * algo_params->dy - 2 * algo_params->dx;
			}
			else
			{
				mlx_pixel_put(mlx_params->mlx, mlx_params->window, algo_params->x, algo_params->y, color);
				algo_params->p = algo_params->p + 2 * algo_params->dy;
			}
			algo_params->x = algo_params->x + 1;
		}
	}
	if (algo_params->m >= 1)
	{

	}
}

/*
Step 1 : Except the two end points of Line from User.
Step 2 : Calculate the slope(m) of the required Line.
Step 3 : Identify the value of slope(m).
	Step 3.1 : If slope(m) is Less than 1 i.e: m < 1
		* Step 3.1.1 : Calculate the constants dx, dy, 2dy, and (2dy – 2dx) and get the first value for the decision parameter as -
		* p0 = 2dy − dx
		* Step 3.1.2 : At each Xk along the line, starting at k = 0, perform the following test −
		* If pk < 0, the next point to plot is (xk + 1,yk) and
		pk+1 = pk + 2dy
		else
		* plot (xk,yk + 1)
		* pk+1 = pk + 2dy − 2dx
		* Step 3.1.3 : Repeat step 4(dx - 1) times.

	Step 3.2 : If slope(m) is greater than or equal to 1 i.e: m >= 1
		* Step 3.2.1 : Calculate the constants dx, dy, 2dy, and (2dy – 2dx) and get the first value for the decision parameter as -
		* p0 = 2dx − dy
		* Step 3.2.2 : At each Yk along the line, starting at k = 0, perform the following test −
		* If pk < 0, the next point to plot is (xk,yk + 1) and
		pk+1 = pk + 2dx
		else
		* plot (xk + 1,yk)
		* pk+1 = pk + 2dx − 2dy
		* Step 3.2.3 : Repeat step 4(dy - 1) times.
 */