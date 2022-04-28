/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:22:28 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/28 10:53:50 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing_digit(int argc, char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tab[j] && j < argc)
	{
		if (tab[j][0] == '\0')
			return ((int)write(1, "Error\n", 6));
		while (tab[j][i])
		{
			if (tab[j][i] == '-' || tab[j][i] == '+')
			{
				if (i != 0)
					return ((int)write(1, "Error\n", 6));
				i++;
			}
			if (ft_isdigit(tab[j][i]) == 0)
				return ((int)write(1, "Error\n", 6));
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	parsing_int(int argc, char **tab)
{
	int	j;

	j = 1;
	while (tab[j] && j < argc)
	{
		if (ft_strlen(tab[j]) > 11)
			check_0_before_nb(tab[j]);
		if (ft_atol(tab[j]) > INT32_MAX || ft_atol(tab[j]) < INT32_MIN \
			|| ft_strlen(tab[j]) > 11)
			return ((int)write(1, "Error\n", 6));
		j++;
	}
	return (0);
}

int	parsing_duplicates(int argc, char **tab)
{
	int	i;
	int	j;

	i = 2;
	j = 1;
	while (tab[j] && j < argc - 1)
	{
		while (tab[j] && tab[i] && j < argc - 1)
		{
			if (ft_atoi(tab[j]) == ft_atoi(tab[i]))
				return ((int)write(1, "Error\n", 6));
			i++;
		}
		j++;
		i = j + 1;
	}
	return (0);
}

int	parsing(int argc, char **argv)
{
	if (parsing_digit(argc, argv) == 0 \
		&& parsing_int(argc, argv) == 0 \
		&& parsing_duplicates(argc, argv) == 0 \
		&& argc > 1)
		return (0);
	else
		return (1);
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
