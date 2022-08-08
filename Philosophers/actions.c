/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:37:34 by dbouron           #+#    #+#             */
/*   Updated: 2022/08/08 17:41:04 by dbouron          ###   ########.fr       */
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
	philo->t_last_meal = get_time();//apparently need mutex here
	print_action(philo, HAS_EATEN);
	ft_usleep(philo->param->t_eat);
	philo->philo_status = HAS_EATEN;
	philo->eat_num++;
	if (philo->eat_num == philo->param->eat_nbr)
		philo->philo_status = SATIATED;
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
	pthread_mutex_lock(&philo->param->die);
	print_action(philo, HAS_DIED);
	philo->philo_status = HAS_DIED;
	philo->param->dead = 1;
	pthread_mutex_unlock(&philo->param->die);
}
