/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:37:34 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/19 17:45:22 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(t_thread_info *philo)
{
	//bloque la fourchette prise
	pthread_mutex_lock(&philo->fork);
}

void	ft_eat(t_thread_info *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	philo->t_last_meal = time.tv_sec + 1000000 * time.tv_usec;
	printf("timestamp %d is eating\n", philo->philo_num);
	usleep(philo->param.t_eat * 1000);
	philo->philo_status = HAS_EATEN;
	//libère les 2 fourchettes;
	pthread_mutex_unlock(&philo->fork);
}

void	ft_sleep(t_thread_info *philo)
{
	printf("timestamp %d is sleeping\n", philo->philo_num);
	usleep(philo->param.t_sleep * 1000);
	philo->philo_status = HAS_SLEPT;
}

void	ft_think(t_thread_info *philo)
{
	printf("timestamp %d is thinking\n", philo->philo_num);
	philo->philo_status = THINKING;
}

void	ft_die(t_thread_info *philo)
{
	printf("timestamp %d died\n", philo->philo_num);
	philo->philo_status = HAS_DIED;
}
