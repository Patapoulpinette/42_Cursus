/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:43:39 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/21 16:33:10 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialization(t_thread_info *philos, int thread_num, t_param *param)
{
	philos[thread_num].philo_num = thread_num + 1;
	philos[thread_num].philo_status = THINKING;
	philos[thread_num].t_last_meal = get_time();
	if (thread_num > 0)
		philos[thread_num].right_fork = &philos[thread_num - 1].left_fork;
	else
		philos[thread_num].right_fork = &philos[param->philo_nbr - 1].left_fork;
	philos[thread_num].param = param;
}

int	execution(t_param *param, t_thread_info *philos)
{
	int	thread_num;
	int	id;

	thread_num = 0;
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

	thread_num = 0;
	while (thread_num < param->philo_nbr)
	{
		id = pthread_join(philos_group[thread_num].thread_id, NULL);
		//id = pthread_detach(philos_group[thread_num].thread_id); //n'attend pas forcément que les thread soient terminés
		if (id)
			return (EXIT_FAILURE);
		printf("thread #%d joined\n", philos_group[thread_num].philo_num);
		//printf("thread #%d detached\n", philos_group[thread_num].philo_num);
		thread_num++;
	}
	free(philos_group);
	return (0);
}
