/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:22:17 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/20 14:27:29 by dbouron          ###   ########.fr       */
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

char	**parsing(char *str)
{
	int			i = 0;
	int			fd;
	int			check_reading;
	static char	*result_reading = NULL;
	char		**map_tab;

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
	map_tab = ft_split(result_reading, '\n');
	while (map_tab[i])
		printf("%s\n", map_tab[i++]);
	free(result_reading);
	return (map_tab);
}
