/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:33:54 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/21 16:22:28 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//TODO - parsing : GNL [✓] + split [✓] + atoi
//à chaque ligne lue (GNL) y++ et x revient à 0
//indice  tableau = x
//Puis, pour chaque point p je dessine une ligne avec le point suivant et le point du dessous (en gros i + 1 et j + 1)

int	main(int argc, char **argv)
{
	char	**map_tab;

	if (argc == 2)
	{
		map_tab = parsing(argv[1]);
		display_window();
		free_tab(map_tab);
	}
	return (0);
}
