/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:48:48 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/07 18:41:54 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int argc, char **argv)
{
	int	j;

	j = 1;
	if (argc == 5 || argc == 6)
	{
		while (argv[j])
		{
			if (check_digits(argv[j]) || check_limits(j, argv[j]))
				return (EXIT_FAILURE);
			j++;
		}
	}
	else
		return (print_parsing_error(1));
	return (EXIT_SUCCESS);
}

int	check_digits(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (print_parsing_error(2));
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (i != 0)
				return (print_parsing_error(3));
			i++;
		}
		if (ft_isdigit(str[i]))
			return (print_parsing_error(4));
		i++;
	}
	return (0);
}

int	check_limits(int arg_nb, char *str)
{
	if (ft_strlen(str) > 8)
		check_0_before_nb(str);
	if (arg_nb == 1 && \
		(ft_atoi(str) < PHILO_MIN || ft_atoi(str) > PHILO_MAX || \
		ft_strlen(str) > 4))
		return (print_parsing_error(5));
	if ((arg_nb >= 2 && arg_nb <= 4) && \
		(ft_atoi(str) < TIME_MIN || ft_atoi(str) > TIME_MAX || \
		ft_strlen(str) > 8))
		return (print_parsing_error(6));
	if (arg_nb == 5 && \
		(ft_atoi(str) < MEAL_MIN || ft_atoi(str) > MEAL_MAX || \
		ft_strlen(str) > 4))
		return (print_parsing_error(7));
	return (0);
}

void	check_0_before_nb(char *str)
{
	int	i;
	int	k;

	i = 0;
	if ((str[0] == '-' || str[0] == '+' || str[0] == '0') && str[1])
	{
		k = 0;
		while (str[i] && (str[i] == '-' || str[i] == '+' || str[i] == '0'))
			i++;
		if (!str[i])
			str[k++] = '0';
		if (str[0] == '-')
			k = 1;
		while (str[i])
			str[k++] = str[i++];
		str[k] = '\0';
	}
}
