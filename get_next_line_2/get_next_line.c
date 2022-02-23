/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:03:23 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/23 16:26:06 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
#if BUFFER_SIZE <= 0
# error "NEGATIVE BUFFER SIZE"
#endif

char	*reading(int fd, char *backup)
{
	int		size;
	char	buffer[BUFFER_SIZE + 1];

	size = read(fd, buffer, BUFFER_SIZE);
	if (size == -1)
		return (NULL);
	buffer[size] = '\0';
	backup = ft_strjoin_gnl(backup, buffer);
	if (!backup)
		return (NULL);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*result;

	while (ft_strchr_gnl(backup, '\n') == -1)
	{
		backup = reading(fd, backup);
		if (!backup)
			return (NULL);
	}
	result = ft_substr(backup, 0, ft_strchr_gnl(backup, '\n'));
	if (!result)
		return (NULL);
	backup = ft_substr(backup, ft_strchr_gnl(backup, '\n') + 1, \
		ft_strlen(backup) - ft_strchr_gnl(backup, '\n') - 1);
	return (result);
}
