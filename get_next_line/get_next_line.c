/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:03:23 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/22 19:05:58 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
#if BUFFER_SIZE <= 0
# error "NEGATIVE BUFFER SIZE"
#endif

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*backup = NULL;
	char		*result;
	int			size;

	while (ft_mystrchr(backup, '\n') == -1 && ft_mystrchr(buffer, '\n') == -1)
	{
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
			char* sub_string =  ft_substr(buffer, 0, ft_mystrchr(buffer, '\n'));
			result = ft_strjoin(backup, sub_string);
			free(sub_string);
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
		backup = ft_strjoin(backup, buffer);
	}
	if (ft_mystrchr(backup, '\n') != -1)
	{
		result = ft_substr(backup, 0, ft_mystrchr(backup, '\n'));
		if (!result)
			return (NULL);
		backup = ft_substr(backup, ft_mystrchr(backup, '\n') + 1, ft_strlen(backup) - ft_mystrchr(backup, '\n') - 1);
		if (!backup)
			return (NULL);
		return (result);
	}
	return (NULL);
}
