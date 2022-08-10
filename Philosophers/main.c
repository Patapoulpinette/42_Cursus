/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:13:21 by dbouron           #+#    #+#             */
/*   Updated: 2022/08/09 13:31:52 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_param			param;
	t_thread_info	*philos;

	if (parsing(argc, argv, &param))
		return (EXIT_FAILURE);
	philos = ft_calloc(param.philo_nbr, sizeof(t_thread_info));
	if (!philos)
		return (EXIT_FAILURE);
	execution(&param, philos);
	ending(&param, philos);
	return (0);
}
