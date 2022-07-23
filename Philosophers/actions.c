/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:37:34 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/23 18:48:12 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(t_thread_info *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	print_action(philo, HAS_FORK);
	if (philo->param->philo_nbr == 1)
	{
		ft_usleep(philo->param->t_die);
		ft_die(philo);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, HAS_FORK);
	philo->philo_status = HAS_FORKS;
}

void	ft_eat(t_thread_info *philo)
{
	philo->t_last_meal = get_time();
	print_action(philo, HAS_EATEN);
	ft_usleep(philo->param->t_eat);
	philo->philo_status = HAS_EATEN;
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleep(t_thread_info *philo)
{
	print_action(philo, HAS_SLEPT);
	ft_usleep(philo->param->t_sleep);
	philo->philo_status = HAS_SLEPT;
}

void	ft_think(t_thread_info *philo)
{
	print_action(philo, THINKING);
	philo->philo_status = THINKING;
}

void	ft_die(t_thread_info *philo)
{
	print_action(philo, HAS_DIED);
	philo->philo_status = HAS_DIED;
}
