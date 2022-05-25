/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:33:54 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/25 16:38:02 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Pour chaque point je dessine une ligne avec le point suivant et le point du dessous (en gros i + 1 et j + 1)

int	main(int argc, char **argv)
{
	t_maps_coord	maps_coord;

	if (argc == 2)
	{
		parsing(&maps_coord, argv[1]);
		display_window(&maps_coord);
		free_tab_i(maps_coord.map_tab);
		free(maps_coord.map_tab);
	}
	return (0);
}
