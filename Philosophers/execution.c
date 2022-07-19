/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:43:39 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/19 11:31:15 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	execution(t_param *param, t_thread_info *philos)
{
	int	thread_num;
	int	id;

	thread_num = 0;
	while (thread_num < param->philo_nbr)
	{
		philos[thread_num].philo_num = thread_num + 1;
		id = pthread_create(&philos[thread_num].thread_id, NULL, &philos_routine, &philos[thread_num]);
		if (id)
			return (EXIT_FAILURE);
		thread_num++;
	}
	return (0);
}

/**
 * @param philo_thread
 *	- Il faut que la fourchette soit disponible (géré par le mutex je crois)
 *	  et que le philo ait moins de 2 fourchettes
 *		◦ timestamp_in_ms X has taken a fork
 *	- Il faut que le philo ait 2 fourchettes
 *		◦ timestamp_in_ms X is eating
 *	- Il faut que le philosophe vienne de manger
 *		◦ timestamp_in_ms X is sleeping
 *	- En attendant d’avoir 2 fourchettes après avoir dormi
 *		◦ timestamp_in_ms X is thinking
 *	- Si le philosophe n’a pas réussi à prendre 2 fourchettes dans les temps
 *	  <time_to_die>
 *		◦ timestamp_in_ms X died
 */

void	*philos_routine(void *philo_thread)
{
	t_thread_info	*philo;
	struct timeval	time;

	philo = philo_thread;
	printf("thread #%d created\n", philo->philo_num);
	philo->philo_status == THINKING;
	while (philo->philo_status != HAS_DIED)
	{
		if (philo->philo_status == THINKING)
			ft_take_fork(&philo);
		if (philo->philo_status == HAS_FORKS)
			ft_eat(&philo);//ne pas oublier de faire gettimeofday pour t_last_meal
		if (philo->philo_status == HAS_EATEN)
			ft_sleep(&philo);
		if (philo->philo_status == HAS_SLEPT)
			ft_think(&philo);
		gettimeofday(&time, NULL);
		if (diff_time(&time, philo->t_last_meal) > philo->param.t_die)
			ft_die(&philo);
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
