/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:03:23 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/11 16:46:23 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define buffer_size 32

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			size;

	if (fd == -1)
		return 0;
	buffer = malloc(sizeof(char) * buffer_size);
	if (!buffer)
		return (0);

	size = read(fd, buffer, buffer_size);
	/* if (size retourne une valeur d'erreur)
		return 0; */
	
}
