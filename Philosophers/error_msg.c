/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:03:54 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/07 18:19:41 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_parsing_error(int nb)
{
	if (nb == 1)
		printf("Error: wrong number of arguments: [number_of_philosophers] " \
				"[time_to_die] [time_to_eat] [time_to_sleep] " \
				"[number_of_times_each_philosopher_must_eat (optional)]\n");
	if (nb == 2)
		printf("Error: empty argument\n");
	if (nb == 3)
		printf("Error: wrong number: put sign before number\n");
	if (nb == 4)
		printf("Error: wrong number: use digit only\n");
	if (nb == 5)
		printf("Error: wrong number_of_philosophers: " \
				"must be between 0 and 200\n");
	if (nb == 6)
		printf("Error: wrong time_to_die/eat/sleep: " \
				"must be between 0 and 2520000 ms\n");
	if (nb == 7)
		printf("Error: wrong number_of_times_each_philosopher_must_eat: " \
				"must be between 0 and 200\n");
	if (nb == 8)
		printf("");
	return (1);
}

//print_exec_error