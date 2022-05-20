
#ifndef ESSAI_H
# define ESSAI_H

# include "minilibx_macos/mlx.h"
# include <unistd.h>//for close
# include <stdio.h>//for printf
# include <stdlib.h>//for exit
# include <fcntl.h>//for open

typedef struct s_mlx_params
{
	void	*mlx;
	void	*window;
	int		x_win;
	int		y_win;
	void	*img;
	char	*img_path;
	int		img_width;
	int		img_height;
}				t_mlx_params;

typedef struct s_maps_params
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}				t_maps_params;

typedef struct s_algo_params
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	float	m;
	int		p;
}				t_algo_params;

//algorithm
void	drawline(t_maps_params	*maps_params, t_mlx_params *mlx_params, t_algo_params *algo_params, int color);

#endif
