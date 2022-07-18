/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:43:39 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/18 09:59:53 by dbouron          ###   ########.fr       */
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

int	execution(t_param *param, t_thread_info *philos_group)
{
	int	thread_num;
	int	id;

	thread_num = 0;
	while (thread_num < param->philo_nbr)
	{
		philos_group[thread_num].philo_num = thread_num + 1;
		id = pthread_create(&philos_group[thread_num].thread_id, NULL, &philos_routine, &philos_group[thread_num]);
		if (id)
			return (EXIT_FAILURE);
		thread_num++;
	}
	return (0);
}

int	ending(t_param *param, t_thread_info *philos_group)
{
	int	thread_num;
	int	id;

	thread_num = 0;
	while (thread_num < param->philo_nbr)
	{
		//id = pthread_join(philos_group[thread_num].thread_id, NULL);
		id = pthread_detach(philos_group[thread_num].thread_id);
		if (id)
			return (EXIT_FAILURE);
		//printf("thread #%d joined\n", philos_group[thread_num].philo_num);
		printf("thread #%d detached\n", philos_group[thread_num].philo_num);
		thread_num++;
	}
	free(philos_group);
	return (0);
}
