/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:03:54 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/07 15:41:17 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_parsing_error(int nb)
{
	if (nb == -1)
		printf("Error: wrong number of arguments: [number_of_philosophers] " \
				"[time_to_die] [time_to_eat] [time_to_sleep] " \
				"[number_of_times_each_philosopher_must_eat (optional)]\n");
	if (nb == 1)
		printf("Error: wrong number_of_philosophers: " \
				"must be between 0 and 200\n");
	if (nb == 2)
		printf("Error: wrong time_to_die: must be between 0 and 2520000 ms\n");
	if (nb == 3)
		printf("Error: wrong time_to_eat: must be between 0 and 2520000 ms\n");
	if (nb == 4)
		printf("Error: wrong time_to_sleep: must be between 0 and 2520000 ms\n");
	if (nb == 5)
		printf("Error: wrong number_of_times_each_philosopher_must_eat: " \
				"must be between 0 and 200\n");
}

//print_exec_error