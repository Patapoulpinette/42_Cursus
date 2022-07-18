/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:13:21 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/18 09:55:32 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_param			param;
	t_thread_info	*philos_group;

	if (parsing(argc, argv, &param))
		return (EXIT_FAILURE);
	philos_group = ft_calloc(param.philo_nbr, sizeof(*philos_group));
	if (!philos_group)
		return (EXIT_FAILURE);
	execution(&param, philos_group);
	ending(&param, philos_group);
	return (0);
}
