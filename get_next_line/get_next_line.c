/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:03:23 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/16 18:12:36 by dbouron          ###   ########lyon.fr   */
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
	size_t		char_in_buffer;
	size_t		char_in_backup;

	if (fd == -1 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (NULL);
	puts("Les parametres donnes sont ok");
	char_in_buffer = ft_mystrchr(buffer, '\n', BUFFER_SIZE);
	puts("1er char in buffer ok");
	char_in_backup = ft_mystrchr(backup, '\n', ft_strlen(backup));
	puts("1er char in backup ok");
	while (char_in_backup == 0 && char_in_buffer == 0)
	{
		puts("avant de lire fd");
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		buffer[size] = '\0';
		puts("Apres avoir lu");
		char_in_buffer = ft_mystrchr(buffer, '\n', BUFFER_SIZE);
		puts("2eme char in buffer ok");
		if (char_in_buffer != 0)
		{
			result = ft_strjoin(backup, ft_substr(buffer, 0, char_in_buffer));
			if (!result)
				return (NULL);
			puts("Result ok");
			backup = ft_substr(buffer, char_in_buffer, \
				ft_strlen(buffer) - char_in_buffer);
			if (!backup)
				return (NULL);
			puts("backup ok");
			return (result);
		}
	}
	if (ft_mystrchr(backup, '\n') != 0)
	{
		result = ft_substr(backup, 0, char_in_backup);
		if (!result)
			return (NULL);
		puts("lecture de backup et result ok");
		backup = ft_substr(backup, char_in_backup, \
			ft_strlen(backup) - char_in_backup);
		if (!backup)
			return (NULL);
		puts("Result de backup ok");
		return (result);
	}
	return (NULL);
}
