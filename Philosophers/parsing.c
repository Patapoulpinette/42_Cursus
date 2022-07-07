/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:48:03 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/07 14:56:53 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing(char **arg)
{
	if (parsing_digit(arg) || parsing_limits(arg))
		exit(EXIT_SUCCESS);
}

int	parsing_digit(char **arg)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (arg[j])
	{
		if (arg[j][0] == '\0')
			return (printf("Error: empty argument\n"));
		while (arg[j][i])
		{
			if (arg[j][i] == '-' || arg[j][i] == '+')
			{
				if (i != 0)
					return (printf("Error: wrong number: put sign before number\n"));
				i++;
			}
			if (ft_isdigit(arg[j][i]) == 0)
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

int	parsing_limits(char **arg)
{
	int	j;
	int	error;

	j = 1;
	error = 0;
	while (arg[j])
	{
		if (ft_strlen(arg[j]) > 8)
			check_0_before_nb(arg[j]);
		printf("arg[%d] = %d\n", j, ft_atoi(arg[j]));
		if (j == 1 && (ft_atoi(arg[j]) < 0 || ft_atoi(arg[j]) > 200 || ft_strlen(arg[j]) > 4))
		{
			print_error(j);
			error++;
		}
		if ((j >= 2 && j <= 4) && (ft_atoi(arg[j]) < 0 || ft_atoi(arg[j]) > 2520000 || ft_strlen(arg[j]) > 8)) //42 minutes
		{
			print_error(j);
			error++;
		}
		if (j == 5 && (ft_atoi(arg[j]) < 0 || ft_atoi(arg[j]) > 200 || ft_strlen(arg[j]) > 4))
		{
			print_error(j);
			error++;
		}
		j++;
	}
	return (error);
}
