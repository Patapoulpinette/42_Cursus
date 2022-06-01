/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:07:48 by dbouron           #+#    #+#             */
/*   Updated: 2022/06/01 17:43:53 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*# define X_WIN_COEF 4
# define Y_WIN_COEF 2.5
# define ZOOM 2*/
# define Z_MULT 3

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
	int	**map_tab;
	int	x_len;
	int	y_len;
	int	x0;
	int	y0;
	int	x1;
	int	y1;
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
void	my_img_pixel_put(t_image *image, int x, int y, int color);
void	draw_in_image(t_image *image, t_maps_coord *map);
int		exit_program(void);
void	display_window(t_maps_coord *map);

//algorithm
void	iso(t_image *image, int *x, int *y, int z);
void draw_last_line(t_image *image, t_maps_coord *map);
void	bhm_line(t_image *image, t_maps_coord *map, int color);

//utils
size_t	ft_tablen(char **tab);

//free
void	free_tab_c(char **tab);
void	free_tab_i(int **tab);

#endif
