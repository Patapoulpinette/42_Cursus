/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:43:39 by dbouron           #+#    #+#             */
/*   Updated: 2022/08/10 22:15:04 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialization(t_thread_info *philos, int thread_num, t_param *param)
{
	int	init_l;

	philos[thread_num].philo_num = thread_num + 1;
	philos[thread_num].philo_status = THINKING;
	philos[thread_num].t_last_meal = get_time();
	philos[thread_num].eat_num = 0;
	if (thread_num > 0)
		philos[thread_num].right_fork = &philos[thread_num - 1].left_fork;
	else
		philos[thread_num].right_fork = &philos[param->philo_nbr - 1].left_fork;
	philos[thread_num].param = param;
	init_l = pthread_mutex_init(&philos[thread_num].left_fork, NULL);
	if (init_l)
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
	check_death(param, philos);
	return (0);
}

void	*philos_routine(void *philo_thread)
{
	t_thread_info	*philo;

	philo = philo_thread;
	if (philo->philo_num % 2 != 0)
	{
		philo->philo_status = HAS_SLEPT;
		usleep(1500);
	}
	while (get_value_protected(&philo->param->dead, &philo->param->die) == 0 && \
		philo->param->eat_nbr != 0 && philo->philo_status != SATIATED)
	{
		if ((get_time() - philo->t_last_meal) > philo->param->t_die)
			ft_die(philo);
		else if (philo->philo_status == THINKING)
			ft_take_fork(philo);
		else if (philo->philo_status == HAS_FORKS)
			ft_eat(philo);
		else if (philo->philo_status == HAS_EATEN)
			ft_sleep(philo);
		else if (philo->philo_status == HAS_SLEPT)
			ft_think(philo);
	}
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}

void	check_death(t_param *param, t_thread_info *philos)
{
	int		index;
	time_t	diff;

	while (get_value_protected(&param->dead, &param->die) == 0)
	{
		index = 0;
		while (index < param->philo_nbr)
		{
			pthread_mutex_lock(&param->last_meal);
			diff = get_time() - philos[index].t_last_meal;
			if (diff >= param->t_die)
			{
				ft_die(&philos[index]);
				return ;
			}
			pthread_mutex_unlock(&param->last_meal);
			index++;
		}
	}
}

int	ending(t_param *param, t_thread_info *philos)
{
	int	thread_num;

	thread_num = 0;
	(void) philos;
	while (thread_num < param->philo_nbr)
	{
		pthread_join(philos[thread_num].thread_id, NULL);
		pthread_mutex_destroy(&philos[thread_num].left_fork);
		thread_num++;
	}
	pthread_mutex_destroy(&param->last_meal);
	pthread_mutex_destroy(&param->display);
	pthread_mutex_destroy(&param->die);
	free(philos);
	return (0);
}
