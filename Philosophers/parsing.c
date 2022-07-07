/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:48:03 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/07 12:11:14 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing(char **arg)
{
	if (parsing_digit(arg) || errors(arg))
		exit(EXIT_SUCCESS);
}

int	parsing_digit(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tab[j])
	{
		if (tab[j][0] == '\0')
			return (printf("Error: empty argument\n"));
		while (tab[j][i])
		{
			if (tab[j][i] == '-' || tab[j][i] == '+')
			{
				if (i != 0)
					return (printf("Error: wrong number: put sign before number\n"));
				i++;
			}
			if (ft_isdigit(tab[j][i]) == 0)
				return (printf("Error: wrong number: use digit only\n"));
			i++;
		}
		i = 0;
		j++;
	}
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

int	errors(char **arg)
{
	int	error;

	error = 0;
	if (ft_atoi(arg[1]) < 0 || ft_atoi(arg[1]) > 200)
	{
		printf("Error: wrong number_of_philosophers: must be between 0 and 200\n");
		error++;
	}
	if (ft_atoi(arg[2]) < 0 || ft_atoi(arg[2]) > INT32_MAX)
	{
		printf("Error: wrong time_to_die: must be between 0 and INT_MAX\n");
		error++;
	}
	if (ft_atoi(arg[3]) < 0 || ft_atoi(arg[3]) > INT32_MAX)
	{
		printf("Error: wrong time_to_eat: must be between 0 and INT_MAX\n");
		error++;
	}
	if (ft_atoi(arg[4]) < 0 || ft_atoi(arg[4]) > INT32_MAX)
	{
		printf("Error: wrong time_to_sleep: must be between 0 and INT_MAX\n");
		error++;
	}
	if (arg[5] && (ft_atoi(arg[5]) < 0 || ft_atoi(arg[5]) > INT32_MAX))
	{
		printf("Error: wrong number_of_times_each_philosopher_must_eat: must be between 0 and INT_MAX\n");
		error++;
	}
	return (error);
}
