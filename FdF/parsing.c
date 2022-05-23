/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:22:17 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/23 16:06:28 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	reading(int fd, char **backup)
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

static void	fill_tab_i(int **tab_i, char **tab_c, int i)
{
	int	j;
	int	start;
	int	end;

	j = 0;
	end = 0;
	tab_i[i] = ft_calloc(sizeof(int), ft_nbword(tab_c[i], ' '));
	if (!tab_i[i])
		return ;
	while (tab_c[i][end])
	{
		while (tab_c[i][end] == ' ')
			end++;
		start = end;
		while (tab_c[i][end] != ' ')
			end++;
		tab_i[i][j] = ft_atoi(ft_substr(tab_c[i], start, end - start));
		j++;
	}
}

static int	**tabc_to_tabi(char **tab_c)
{
	int	**tab_i;
	int	i;

	i = 0;
	tab_i = ft_calloc(sizeof(int *), ft_tablen(tab_c));
	if (!tab_i)
		return (NULL);
	while (tab_c[i])
	{
		fill_tab_i(tab_i, tab_c, i);
		i++;
	}
	return (tab_i);
}

int	**parsing(char *str)
{
	int			i = 0;//for testing
	int			j = 0;//for testing
	int			fd;
	int			check_reading;
	static char	*result_reading = NULL;
	char		**map_tab_c;
	int			**map_tab_i;

	fd = open(str, O_RDONLY);
	printf("open : %d\n", fd);
	if (fd == -1)
		return (0);
	check_reading = 1;
	while (check_reading != 0)
	{
		check_reading = reading(fd, &result_reading);
		if (!result_reading)
			return (0);
	}
	close(fd);
	map_tab_c = ft_split(result_reading, '\n');
	while (map_tab_c[i])//for testing
		printf("%s\n", map_tab_c[i++]);//for testing
	//convert char ** into int **
	map_tab_i = tabc_to_tabi(map_tab_c);
	i = 0;//for testing
	while (map_tab_i[i])//for testing
	{
		while (map_tab_i[i][j])
		{
			printf("%d", map_tab_i[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free(result_reading);
	free_tab_c(map_tab_c);
	return (map_tab_i);
}
