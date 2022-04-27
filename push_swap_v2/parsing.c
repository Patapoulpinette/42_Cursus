/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:22:28 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/27 11:32:31 by dbouron          ###   ########.fr       */
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
			return (write(1, "Error\n", 6));
		while (tab[j][i])
		{
			if (tab[j][i] == '-' || tab[j][i] == '+')
			{
				if (i != 0)
					return (write(1, "Error\n", 6));
				i++;
			}
			if (ft_isdigit(tab[j][i]) == 0)
				return (write(1, "Error\n", 6));
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
		check_0_before_nb(tab[j]);
		if (ft_strcmp(tab[j], ft_itoa(ft_atoi(tab[j]))))
			return (write(1, "Error\n", 6));
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
				return (write(1, "Error\n", 6));
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	check_0_before_nb(char *str)
{
	int	i;
	int	k;

	i = 0;
	if (str[0] == '-' || str[0] == '+' || str[0] == '0')
	{
		while (str[i] && (str[i] == '-' || str[i] == '+' || str[i] == '0'))
			i++;
		if (str[0] == '-')
			k = 1;
		else
			k = 0;
		while (str[i])
			str[k++] = str[i++];
		str[k] = '\0';
	}
}
