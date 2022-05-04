/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:33:54 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/04 14:28:58 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//TODO - parsing : GNL + split + atoi
//à chaque ligne lue (GNL) y++ et x revient à 0
//indice  tableau = x

int	main(int argc, char **argv)
{
	int		fd;
	char	*result = NULL;

	if (argc == 2)
	{
		//parsing
		fd = open(argv[1], O_RDONLY);
		printf("open : %d\n", fd);
		if (fd == -1)
			return (0);
		while (1)
		{
			result = get_next_line(fd);
			if (!result)
				break ;
			dprintf(2, "%s", result);
			free(result);
		}
		close(fd);
	}
	return (0);
}
