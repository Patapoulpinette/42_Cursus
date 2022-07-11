/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:03:54 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/11 11:26:46 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_parsing_error(int nb)
{
	static const char *const	error_messages[] = {
		NULL,
		"wrong number of arguments: [number_of_philosophers] " \
			"[time_to_die] [time_to_eat] [time_to_sleep] " \
			"[number_of_times_each_philosopher_must_eat (optional)]",
		"empty argument",
		"wrong number: put sign before number",
		"wrong number: use digits only",
		"wrong number_of_philosophers: must be between 1 and 200",
		"wrong time_to_die/eat/sleep: must be between 0 and 2520000 ms",
		"wrong number_of_times_each_philosopher_must_eat: " \
			"ust be between 0 and 200",
	};

	printf("Error: %s\n", error_messages[nb]);
	return (1);
}

//print_exec_error