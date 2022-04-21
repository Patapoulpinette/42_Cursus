/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:41:09 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/21 21:09:31 by dbouron          ###   ########lyon.fr   */
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

int	parsing_int(int argc, char **tab)//TODO
{
	int	j;

	j = 1;
	while (tab[j] && j < argc)
	{
		if (ft_atol(tab[j]) > INT_MAX || ft_atol(tab[j]) < INT_MIN)
			return (/*ft_*/printf("Error\n"));
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
	int	i;
	int	j;
	t_data_stack	stacks;
	
	if (parsing_digit(argc, argv) == 0 &&
		parsing_int(argc, argv) == 0 &&
		parsing_duplicates(argc, argv) == 0)
	{
		dprintf(2, "parsing ok\n");//for testing
		i = 1;
		j = 0;
		stacks.size_a = argc - 1;
		stacks.size_b = 0;
		stacks.stack_a = malloc(sizeof(int *) * stacks.size_a);
		stacks.stack_b = malloc(sizeof(int *) * stacks.size_a);
		if (!stacks.stack_a || !stacks.stack_b)
			return (0);
		while (argv[i] && i < argc)
			stacks.stack_a[j++] = ft_atoi(argv[i++]);
		stacks.stack_a = indexing(stacks);
		ft_algo_of_fire(stacks);
		j = 0;//for testing
		while (j < argc - 1)//for testing
			dprintf(2, "%d\n", stacks.stack_a[j++]);//for testing
		free(stacks.stack_a);
		free(stacks.stack_b);
		return (0);
		}
	return (0);
}
