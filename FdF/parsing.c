/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:22:17 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/30 21:03:08 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	reading(int fd, char **backup)
{
	ssize_t	size;
	char	buffer[BUFFER_SIZE + 1];

	size = read(fd, buffer, BUFFER_SIZE);
	if (size == -1)
		return (-1);
	if (size == 0)
		return (0);
	buffer[size] = '\0';
	*backup = ft_strjoin_free(*backup, buffer);
	if (!backup)
		return (-1);
	return (1);
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
		dprintf(2, "%d ", map->map_tab[i][j]);//for testing
		j++;
	}
	dprintf(2, "\n");//for testing
	map->x_len = j;
	map->y_len = i + 1;
}

void	tabc_to_tabi(t_maps_coord *map, char **tab_c)
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

void	parsing(t_maps_coord *map, char *str)
{
	int				i = 0;//for testing
	int				fd;
	int				check_reading;
	static char		*result_reading = NULL;
	char			**map_tab_c;

	fd = open(str, O_RDONLY);
	printf("open : %d\n", fd);//for testing
	if (fd == -1)
		return ;
	check_reading = 1;
	while (check_reading != 0)
	{
		check_reading = reading(fd, &result_reading);
		if (!result_reading)
			return ;
	}
	close(fd);
	map_tab_c = ft_split(result_reading, '\n');
	while (map_tab_c[i])//for testing
		printf("%s\n", map_tab_c[i++]);//for testing
	dprintf(2, "\n");//for testing
	//convert char ** into int **
	tabc_to_tabi(map, map_tab_c);
	free(result_reading);
	free_tab_c(map_tab_c);
}
