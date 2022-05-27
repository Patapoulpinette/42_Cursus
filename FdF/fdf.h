/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:07:48 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/27 15:46:56 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# if BUFFER_SIZE <= 0
#  error "NEGATIVE BUFFER SIZE"
# endif

# include "minilibx_macos/mlx.h"
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

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
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

//main

//parsing
void	parsing(t_maps_coord *maps_coord, char *str);
int		reading(int fd, char **backup);

//graphical_part
int		press_key(int key, t_mlx_params *mlx_params);
void	my_mlx_pixel_put(t_image *image, t_maps_coord *maps_coord, int x, int y, int color);
void	draw_in_image(t_image *image, t_maps_coord *maps_coord);
int		exit_program(void);
void	display_window(t_maps_coord *maps_coord);

//algorithm
void	iso(int *x, int *y, int z);
void	bhm_line(t_image *image, t_maps_coord *maps_coord, int x1, int y1, int x2, int y2, int color);

//len
size_t	ft_strlen(const char *s);
size_t	ft_tablen(char **tab);

//utils
int		ft_atoi(const char *str);
char	*ft_strjoin_free(char *s1, char *s2);

//free
void	free_tab_c(char **tab);
void	free_tab_i(int **tab);

//utils_split
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t type_size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_nbword(char const *s, char c);

//split
char	**ft_split(char const *s, char c);

#endif
