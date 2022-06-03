/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:22:17 by dbouron           #+#    #+#             */
/*   Updated: 2022/06/03 18:48:45 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_size(int fd)
{
	ssize_t		size;
	int			i;
	static int	len = 0;
	char		buffer[BUFFER_SIZE + 1];

	size = 1;
	while (size != 0)
	{
		i = 0;
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (-1);
		buffer[size] = '\0';
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				len++;
			i++;
		}
	}
	return (len);
}

static void	fill_tab_i(t_maps_coord	*map, char **tab_c, int i)
{
	int	j;
	int	start;
	int	end;
	int	nb_word;

	j = 0;
	end = 0;
	nb_word = (int)ft_nbword(tab_c[i], ' ');
	map->map_tab[i] = ft_calloc(sizeof(int), nb_word);
	if (!map->map_tab[i])
		return ;
	while (j < nb_word)
	{
		while (tab_c[i][end] && tab_c[i][end] == ' ')
			end++;
		start = end;
		while (tab_c[i][end] && tab_c[i][end] != ' ')
			end++;
		map->map_tab[i][j] = ft_atoi(&tab_c[i][start]);
		j++;
	}
	map->x_len = j;
	map->y_len = i + 1;
}

static void	tabc_to_tabi(t_maps_coord *map, char **tab_c)
{
	int	i;

	i = 0;
	map->map_tab = ft_calloc(sizeof(int *), ft_tablen(tab_c));
	if (!map->map_tab)
		return ;
	while (tab_c[i])
	{
		fill_tab_i(map, tab_c, i);
		i++;
	}
}

static void	save_map_name(t_maps_coord *map, char const *str)
{
	int	start;
	int	end;
	int	i;

	end = 0;
	i = 0;
	while (str[end] != '/')
		end++;
	start = end + 1;
	while (str[end] != '.')
		end++;
	map->name = ft_calloc(end - start + 1, sizeof(char));
	while (start < end)
		map->name[i++] = str[start++];
	map->name[i] = '\0';
	if (ft_strncmp(str + end, "fdf", 3) != 0)
		exit (EXIT_FAILURE);
}

void	parsing(t_maps_coord *map, char *str)
{
	int		fd;
	int		len;
	int		j;
	char	**map_tab_c;

	save_map_name(map, str);
	j = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error();
	len = read_size(fd);
	if (len == 0)
		exit (0);
	close(fd);
	map_tab_c = ft_calloc(sizeof(char *), len + 1);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_error();
	while (j < len)
		map_tab_c[j++] = get_next_line(fd);
	close(fd);
	tabc_to_tabi(map, map_tab_c);
	free_tab_c(map_tab_c);
}
