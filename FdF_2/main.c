/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:33:54 by dbouron           #+#    #+#             */
/*   Updated: 2022/06/03 18:08:33 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_maps_coord	map;

	if (argc == 2)
	{
		parsing(&map, argv[1]);
		display_window(&map);
		free_tab_i(map.map_tab, map.y_len);
		free(map.name);
	}
	return (0);
}
