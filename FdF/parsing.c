/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:22:17 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/21 21:26:14 by dbouron          ###   ########.fr       */
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

int	**tabctotabi(char **tab_c)
{
	int	**tab_i;

	tab_i = ft_calloc(sizeof(int *), ft_tablen(tab_c));
	if (!tab_i)
		return (NULL);
}

char	**parsing(char *str)
{
	int			i = 0;
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
	while (map_tab_c[i])
		printf("%s\n", map_tab_c[i++]);
	//convert char ** into int **
	map_tab_i = tabctotabi(map_tab_c);
	free(result_reading);
	return (map_tabi);
}
