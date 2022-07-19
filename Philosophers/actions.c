/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:37:34 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/19 14:32:21 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(t_thread_info *philo)
{
	//bloque la fourchette prise
}

void	ft_eat(t_thread_info *philo)
{
	usleep(philo->param.t_eat * 1000);
	philo->philo_status = HAS_EATEN;
	//libère les 2 fourchettes;
}

void	ft_sleep(t_thread_info *philo)
{
	usleep(philo->param.t_sleep * 1000);
	philo->philo_status = HAS_SLEPT;
}

void	ft_think(t_thread_info *philo)
{
	philo->philo_status = THINKING;
}

void	ft_die(t_thread_info *philo)
{
	philo->philo_status = HAS_DIED;
}
