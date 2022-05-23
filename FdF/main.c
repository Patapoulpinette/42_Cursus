/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:33:54 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/23 19:16:52 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Pour chaque point je dessine une ligne avec le point suivant et le point du dessous (en gros i + 1 et j + 1)

int	main(int argc, char **argv)
{
	int	**map_tab;

	if (argc == 2)
	{
		map_tab = parsing(argv[1]);
		display_window();
		free_tab_i(map_tab);
		free(map_tab);
	}
	return (0);
}
