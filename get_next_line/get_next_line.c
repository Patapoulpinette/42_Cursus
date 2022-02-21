/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:03:23 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/21 19:48:48 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // pour tester avec puts

#define BUFFER_SIZE 32

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*backup = NULL;
	char		*result;
	int			size;

	if (fd == -1 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (NULL);
		puts("HERE");
	while (ft_mystrchr(backup, '\n') == -1 && ft_mystrchr(buffer, '\n') == -1)
	{
		puts("HERE 1");
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		if (size == 0)
		{
			if (!backup)
				return (NULL);
			result = ft_strjoin(backup, NULL);
			backup = NULL;
			return (result);
		}
		buffer[size] = '\0';
		if (ft_mystrchr(buffer, '\n') != -1)
		{
			result = ft_strjoin(backup, ft_substr(buffer, 0, ft_mystrchr(buffer, '\n')));
			if (!result)
				return (NULL);
			if (ft_mystrchr(buffer, '\n') + 1 == (int)ft_strlen(buffer))
				backup = NULL;
			else
			{
				backup = ft_substr(buffer, ft_mystrchr(buffer, '\n') + 1, ft_strlen(buffer) - ft_mystrchr(buffer, '\n') - 1);
				if (!backup)
					return (NULL);
			}
			return (result);
		}
		puts("HERE 2");
		backup = ft_strjoin(backup, buffer);
		puts("HERE 3");
	}
	if (ft_mystrchr(backup, '\n') != -1)
	{
		puts("HERE 4");
		result = ft_substr(backup, 0, ft_mystrchr(backup, '\n'));
		if (!result)
			return (NULL);
		backup = ft_substr(backup, ft_mystrchr(backup, '\n') + 1, ft_strlen(backup) - ft_mystrchr(backup, '\n') - 1);
		if (!backup)
			return (NULL);
		return (result);
	}
		puts("HERE 5");
	return (NULL);
}
