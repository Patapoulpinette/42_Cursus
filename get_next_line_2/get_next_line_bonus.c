/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:11:08 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/24 16:54:13 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	reading(int fd, char **backup)
{
	int		size;
	char	buffer[BUFFER_SIZE + 1];

	size = read(fd, buffer, BUFFER_SIZE);
	if (size == -1)
		return (-1);
	if (size == 0)
		return (0);
	buffer[size] = '\0';
	*backup = ft_strjoin_gnl(*backup, buffer);
	if (!backup)
		return (-1);
	return (1);
}

void	saving(char **backup)
{
	char	*tmp;

	tmp = *backup;
	*backup = ft_substr(*backup, ft_strchr_gnl(*backup, '\n') + 1, \
			ft_strlen(*backup) - ft_strchr_gnl(*backup, '\n') - 1, 0);
	free(tmp);
	return ;
}

char	*get_next_line(int fd)
{
	static char	*backup[256];
	char		*result;
	int			check_reading;

	if (fd < 0 || fd > 256)
		return (NULL);
	while (ft_strchr_gnl(backup[fd], '\n') == -1)
	{
		check_reading = reading(fd, &backup[fd]);
		if (check_reading == -1)
			return (NULL);
		if (check_reading == 0)
		{
			result = ft_substr(backup[fd], 0, ft_strlen(backup[fd]), 1);
			backup[fd] = NULL;
			return (result);
		}
	}
	result = ft_substr(backup[fd], 0, ft_strchr_gnl(backup[fd], '\n') + 1, 0);
	if (!result)
		return (NULL);
	saving(&backup[fd]);
	return (result);
}
