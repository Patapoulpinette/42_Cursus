/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:43:39 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/22 16:34:26 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialization(t_thread_info *philos, int thread_num, t_param *param)
{
	int	init_l;
	int	init_r;

	philos[thread_num].philo_num = thread_num + 1;
	philos[thread_num].philo_status = THINKING;
	philos[thread_num].t_last_meal = get_time();
	if (thread_num > 0)
		philos[thread_num].right_fork = &philos[thread_num - 1].left_fork;
	else
		philos[thread_num].right_fork = &philos[param->philo_nbr - 1].left_fork;
	philos[thread_num].param = param;
	init_l = pthread_mutex_init(&philos[thread_num].left_fork, NULL);
	init_r = pthread_mutex_init(philos[thread_num].right_fork, NULL);
	if (init_l || init_r)
		return (EXIT_FAILURE);
	return (0);
}

int	execution(t_param *param, t_thread_info *philos)
{
	int	thread_num;
	int	id;

	thread_num = 0;
	param->start_time = get_time();
	while (thread_num < param->philo_nbr)
	{
		initialization(philos, thread_num, param);
		id = pthread_create(&philos[thread_num].thread_id, NULL, \
			&philos_routine, &philos[thread_num]);
		if (id)
			return (EXIT_FAILURE);
		thread_num++;
	}
	return (0);
}

void	*philos_routine(void *philo_thread)
{
	t_thread_info	*philo;

	philo = philo_thread;
	printf("thread philo #%d created\n", philo->philo_num);
	while (philo->philo_status != HAS_DIED)
	{
		if (philo->philo_status == THINKING)
			ft_take_fork(philo);
		if (philo->philo_status == HAS_FORKS)
			ft_eat(philo);
		if (philo->philo_status == HAS_EATEN)
			ft_sleep(philo);
		if (philo->philo_status == HAS_SLEPT)
			ft_think(philo);
		if ((get_time() - philo->t_last_meal) > philo->param->t_die)
			ft_die(philo);
	}
	return (NULL);
}

int	ending(t_param *param, t_thread_info *philos_group)
{
	int	thread_num;
	int	id;
	int	dest_l;
	int	dest_r;

	thread_num = 0;
	while (thread_num < param->philo_nbr)
	{
		id = pthread_join(philos_group[thread_num].thread_id, NULL);
		if (id)
			return (EXIT_FAILURE);
		printf("thread #%d joined\n", philos_group[thread_num].philo_num);
		dest_l = pthread_mutex_destroy(&philos_group[thread_num].left_fork);
		dest_r = pthread_mutex_destroy(philos_group[thread_num].right_fork);
		if (dest_l || dest_r)
			return (EXIT_FAILURE);
		thread_num++;
	}
	free(philos_group);
	return (0);
}
