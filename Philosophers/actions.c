/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:37:34 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/21 16:17:59 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(t_thread_info *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	printf("timestamp %d has taken a fork\n", philo->philo_num);
	pthread_mutex_lock(philo->right_fork);
	printf("timestamp %d has taken a fork\n", philo->philo_num);
	philo->philo_status = HAS_FORKS;
}

void	ft_eat(t_thread_info *philo)
{
	philo->t_last_meal = get_time();
	printf("timestamp %d is eating\n", philo->philo_num);
	usleep(philo->param->t_eat * 1000);
	philo->philo_status = HAS_EATEN;
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleep(t_thread_info *philo)
{
	printf("timestamp %d is sleeping\n", philo->philo_num);
	usleep(philo->param->t_sleep * 1000);
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
