/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:07:48 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/23 11:56:10 by dbouron          ###   ########.fr       */
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
# include <stdlib.h>//for exit
# include <fcntl.h>//for open

typedef struct s_mlx_params
{
	void	*mlx;
	void	*window;
	int		x_win;
	int		y_win;
//	void	*img;
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
int		**parsing(char *str);
int		reading(int fd, char **backup);

//graphical_part
int		press_key(int key, t_mlx_params *mlx_params);
int		exit_program(void);
void	display_window(void);

//algorithm
void	drawline(t_maps_params	*maps_params, t_mlx_params *mlx_params, t_algo_params *algo_params, int color);

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
