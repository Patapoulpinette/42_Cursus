/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:13:21 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/11 18:21:02 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philos_routine(void *philos)
{
	t_thread_info	*philo;

	philo = philos;
	printf("thread #%d created\n", philo->philo_num);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_param			param;
	t_thread_info	*philos_group;
	int				thread_num;
	int				id;

	if (parsing(argc, argv, &param))
		return (EXIT_FAILURE);
	philos_group = ft_calloc(param.philo_nbr, sizeof(*philos_group));
	if (!philos_group)
		return (EXIT_FAILURE);
	thread_num = 0;
	while (thread_num < param.philo_nbr)
	{
		philos_group[thread_num].philo_num = thread_num + 1;
		id = pthread_create(&philos_group[thread_num].thread_id, NULL, &philos_routine, &philos_group[thread_num]);
		if (id)
			return (EXIT_FAILURE);
		thread_num++;
	}
	thread_num = 0;
	while (thread_num < param.philo_nbr)
	{
		id = pthread_join(philos_group[thread_num].thread_id, NULL);
		if (id)
			return (EXIT_FAILURE);
		printf("thread #%d joined\n", philos_group[thread_num].philo_num);
		thread_num++;
	}
	free(philos_group);
	return (0);
}
