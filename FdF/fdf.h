/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:07:48 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/06 13:47:41 by dbouron          ###   ########.fr       */
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
# include <stdio.h>//for dprintf
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

//main

//parsing

//algorithm
void	drawline(t_maps_params	*maps_params, t_mlx_params *mlx_params, t_algo_params *algo_params, int color);

//utils
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t type_size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//GNL
char	*get_next_line(int fd);

//split
char	**ft_split(char const *s, char c);

#endif
