/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:41:09 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/19 12:07:07 by dbouron          ###   ########.fr       */
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
		while (tab[j][i])
		{
			if (ft_isdigit(tab[j][i]) == 0)
				return (/*ft_*/printf("Error\n"));
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	parsing_int(int argc, char **tab)
{
//	ft_atoi();
//	ft_itoa();
//	puis comparer
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
		while (tab[j] && tab [i] && j < argc - 1)
		{
			if (ft_atoi(tab[j]) == ft_atoi(tab[i]))
				return (/*ft_*/printf("Error\n"));
			i++;
		}
		j++;
		i = j + 1;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	parsing_digit(argc, argv);
//	parsing_int(argc, argv);
	parsing_duplicates(argc, argv);
//	algorithm
	return (0);
}
