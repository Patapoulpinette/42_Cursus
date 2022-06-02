/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:07:48 by dbouron           #+#    #+#             */
/*   Updated: 2022/06/02 12:15:11 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define X_RESOLUTION 5120
# define Y_RESOLUTION 2880
# define ANGLE 0.46373398
# define Z_MULT 3
# define COLOR_1 0xfb8500
# define COLOR_2 0xffb703

# include "minilibx_macos/mlx.h"
# include "GNL/get_next_line.h"
# include "libft/libft.h"
# include <unistd.h>//for close
# include <stdio.h>//for printf
# include <stdlib.h>//for exit & abs
# include <fcntl.h>//for open
# include <math.h>//for cos & sin

typedef struct s_mlx_params
{
	void	*mlx;
	void	*window;
	int		x_win;
	int		y_win;
}				t_mlx_params;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x_img;
	int		y_img;
}				t_image;

typedef struct s_maps_coord
{
	char	*name;
	int		**map_tab;
	int		x_len;
	int		y_len;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
}				t_maps_coord;

typedef struct s_algo_params
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	dx1;
	int	dy1;
	int	px;
	int	py;
	int	xe;
	int	ye;
}				t_algo_params;

//parsing
int		read_size(int fd);
void	parsing(t_maps_coord *map, char *str);

//graphical_part
int		press_key(int key, t_mlx_params *mlx);
int		exit_program(void);
void	display_window(t_maps_coord *map);

//drawing_part
void	iso(t_image *image, int *x, int *y, int z);
void	my_img_pixel_put(t_image *image, int x, int y, int color);
void	draw_last_line_x(t_image *image, t_maps_coord *map);
void	draw_last_line_y(t_image *image, t_maps_coord *map);
void	draw_in_image(t_image *image, t_maps_coord *map);

//algorithm
void	drawline_1(t_image *image, t_maps_coord *map, t_algo_params *algo, \
					int color);
void	drawline_2(t_image *image, t_algo_params *algo, int color);
void	drawline_3(t_image *image, t_maps_coord *map, t_algo_params *algo, \
					int color);
void	drawline_4(t_image *image, t_algo_params *algo, int color);
void	bhm_line(t_image *image, t_maps_coord *map, int color);

//utils
size_t	ft_tablen(char **tab);

//free
void	free_tab_c(char **tab);
void	free_tab_i(int **tab);

#endif
