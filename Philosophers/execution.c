/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:43:39 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/18 18:40:07 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	execution(t_param *param, t_thread_info *philos_group)
{
	int	thread_num;
	int	id;

	thread_num = 0;
	while (thread_num < param->philo_nbr)
	{
		philos_group[thread_num].philo_num = thread_num + 1;
		id = pthread_create(&philos_group[thread_num].thread_id, NULL, &philos_routine, &philos_group[thread_num]);
		if (id)
			return (EXIT_FAILURE);
		thread_num++;
	}
	return (0);
}

/**
 * @param philos
 *	- Il faut que la fourchette soit disponible (géré par le mutex je crois)
 *	  et que le philo ait moins de 2 fourchettes
 *		◦ timestamp_in_ms X has taken a fork
 *	- Il faut que le philo ait 2 fourchettes
 *		◦ timestamp_in_ms X is eating
 *	- Il faut que le philosophe vienne de manger —> philo_status
 *	  (has taken a fork [1], has taken 2 forks [2], has eaten [3],
 *	  has slept [4], has thank [5], has died [6])
 *		◦ timestamp_in_ms X is sleeping
 *	- En attendant d’avoir 2 fourchettes après avoir dormi
 *		◦ timestamp_in_ms X is thinking
 *	- Si le philosophe n’a pas réussi à prendre 2 fourchettes dans les temps
 *	  <time_to_die>
 *		◦ timestamp_in_ms X died
 */

void	*philos_routine(void *philos)
{
	t_thread_info	*philo;

	philo = philos;
	printf("thread #%d created\n", philo->philo_num);
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
		//id = pthread_detach(philos_group[thread_num].thread_id); //marche pas tout le temps et je sais pas pourquoi
		if (id)
			return (EXIT_FAILURE);
		printf("thread #%d joined\n", philos_group[thread_num].philo_num);
		//printf("thread #%d detached\n", philos_group[thread_num].philo_num);
		thread_num++;
	}
	free(philos_group);
	return (0);
}
