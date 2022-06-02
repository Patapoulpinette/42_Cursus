/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:33:54 by dbouron           #+#    #+#             */
/*   Updated: 2022/06/02 11:35:31 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
