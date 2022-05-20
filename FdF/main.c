/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:33:54 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/20 11:49:16 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//TODO - parsing : GNL + split + atoi
//à chaque ligne lue (GNL) y++ et x revient à 0
//indice  tableau = x
//Puis, pour chaque point p je dessine une ligne avec le point suivant et le point du dessous (en gros i + 1 et j + 1)

static int	reading(int fd, char **backup)
{
	ssize_t	size;
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

int	main(int argc, char **argv)
{
	int		fd;
	char	*result = NULL;
	int		check_reading;

	if (argc == 2)
	{
		//parsing
		fd = open(argv[1], O_RDONLY);
		printf("open : %d\n", fd);
		if (fd == -1)
			return (0);
		check_reading = 1;
		while (check_reading != 0)
		{
			check_reading = reading(fd, &result);
			if (!result)
				break ;
			dprintf(2, "%s", result);
			free(result);
		}
		close(fd);
	}
	return (0);
}
