/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:03:23 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/15 19:19:49 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define buffer_size 32

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*backup;
	char		*result;
	int			size;

	if (fd == -1)
		return (NULL);
	buffer = malloc(sizeof(char) * buffer_size);
	if (!buffer)
		return (NULL);

	size = read(fd, buffer, buffer_size);
	/* if (size retourne une valeur d'erreur)
		return 0; */
	if (ft_strchr(buffer, '\n') != 0)
	{
		result = ft_strjoin(backup, ft_substr(buffer, 0, ft_strchr(buffer, '\n')));
		backup = ft_substr(buffer, ft_strchr(buffer, '\n'), ft_strlen(buffer) - ft_strchr(buffer, '\n'));
	}
	return (result);
}
