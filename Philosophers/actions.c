/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:37:34 by dbouron           #+#    #+#             */
/*   Updated: 2022/08/10 22:13:08 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(t_thread_info *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	print_action(philo, HAS_FORK, 0);
	if (philo->param->philo_nbr == 1)
	{
		ft_usleep(philo->param->t_die);
		ft_die(philo);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, HAS_FORK, 0);
	philo->philo_status = HAS_FORKS;
}

void	ft_eat(t_thread_info *philo)
{
	pthread_mutex_lock(&philo->param->last_meal);
	philo->t_last_meal = get_time();
	pthread_mutex_unlock(&philo->param->last_meal);
	print_action(philo, HAS_EATEN, 0);
	ft_usleep(philo->param->t_eat);
	philo->philo_status = HAS_EATEN;
	if (philo->eat_num == philo->param->eat_nbr)
	{
		philo->philo_status = SATIATED;
		pthread_mutex_lock(&philo->param->die);
		philo->param->dead = 3;
		pthread_mutex_unlock(&philo->param->die);
	}
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleep(t_thread_info *philo)
{
	print_action(philo, HAS_SLEPT, 0);
	ft_usleep(philo->param->t_sleep);
	philo->philo_status = HAS_SLEPT;
	philo->eat_num++;
}

void	ft_think(t_thread_info *philo)
{
	print_action(philo, THINKING, 0);
	philo->philo_status = THINKING;
}

void	ft_die(t_thread_info *philo)
{
	pthread_mutex_lock(&philo->param->die);
	if (philo->param->dead == 0)
		philo->param->dead = 1;
	if (philo->param->dead == 1)
	{
		pthread_mutex_unlock(&philo->param->die);
		print_action(philo, HAS_DIED, 1);
		pthread_mutex_lock(&philo->param->die);
		philo->param->dead = 2;
		pthread_mutex_unlock(&philo->param->die);
	}
	pthread_mutex_unlock(&philo->param->die);
}
