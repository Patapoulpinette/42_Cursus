/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:37:34 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/19 12:08:02 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork()
{

}

void	ft_eat(t_thread_info *philo)
{
	usleep(philo->param.t_eat * 1000);
	philo->philo_status == HAS_EATEN;
	//libère les 2 fourchettes;
}

void	ft_sleep()
{

}

void	ft_think()
{

}

void	ft_die()
{

}
