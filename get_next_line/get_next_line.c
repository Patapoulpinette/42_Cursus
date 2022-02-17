/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:03:23 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/17 21:32:30 by dbouron          ###   ########lyon.fr   */
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
	puts("Les parametres donnes sont ok");
	while (ft_mystrchr(backup, '\n', ft_strlen(backup)) == -1 \
		&& ft_mystrchr(buffer, '\n', BUFFER_SIZE) == -1)
	{
		puts("Je rentre dans le boucle while car il n'y a pas de \\n");
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		if (size == 0)
		{
			free(backup);
			backup = NULL;
			return (NULL);
		}
		buffer[size] = '\0';
		printf("Apres avoir lu :\n - size = %d\n - buffer = %s\n", size, buffer);
		if (ft_mystrchr(buffer, '\n', BUFFER_SIZE) != -1)
		{
			puts("Je rentre dans le if car il y a un \\n");
			result = ft_strjoin(backup, ft_substr(buffer, 0, \
				ft_mystrchr(buffer, '\n', BUFFER_SIZE)));
			if (!result)
				return (NULL);
			puts("Result ok");
			backup = ft_substr(buffer, ft_mystrchr(buffer, '\n', BUFFER_SIZE), \
				ft_strlen(buffer) - ft_mystrchr(buffer, '\n', BUFFER_SIZE));
			if (!backup)
				return (NULL);
			puts("backup ok");
			return (result);
		}
		backup = ft_strjoin(backup, buffer);
		printf("backup = %s\n", backup);
	}
	if (ft_mystrchr(backup, '\n') != -1)
	{
		result = ft_substr(backup, 0, ft_mystrchr(backup, '\n', \
			ft_strlen(backup)));
		if (!result)
			return (NULL);
		puts("lecture de backup et result ok");
		backup = ft_substr(backup, ft_mystrchr(backup, '\n', \
			ft_strlen(backup)), ft_strlen(backup) - ft_mystrchr(backup, '\n', \
			ft_strlen(backup)));
		if (!backup)
			return (NULL);
		puts("Result de backup ok");
		return (result);
	}
	return (NULL);
}
