/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:41:09 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/25 18:24:37 by dbouron          ###   ########.fr       */
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
		if (ft_atol(tab[j]) > INT32_MAX || ft_atol(tab[j]) < INT32_MIN \
			|| ft_strlen(tab[j]) > 11)
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

int	main(int argc, char **argv)//TODO parsing with "" & sorting_5nbrs with less than 13 operations
{
	int				i;
	int				j;
	t_data_stack	stacks;

	if (parsing_digit(argc, argv) == 0 \
		&& parsing_int(argc, argv) == 0 \
		&& parsing_duplicates(argc, argv) == 0 \
		&& argc > 1)
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

		i = 0;//for testing
		j = 0;//for testing
		dprintf(2, "init----------------\n");//for testing
		while (j < stacks.size_a)//for testing
			dprintf(2, "\t%d\n", stacks.stack_a[j++]);//for testing
		dprintf(2, "     Stack A\n");//for testing

		if (stacks.size_a == 2)
			while (!is_sorted(&stacks))
				swap_a(&stacks, 1);
		else if (stacks.size_a == 3)
			sorting_3nbrs(&stacks);
		else if (stacks.size_a == 5)
			sorting_5nbrs(&stacks);
		else
			sorting_radix(&stacks);

		i = 0;//for testing
		j = 0;//for testing
		dprintf(2, "algo----------------\n");//for testing
		while (j < stacks.size_a)//for testing
			dprintf(2, "\t%d\n", stacks.stack_a[j++]);//for testing
		dprintf(2, "     Stack A\n");//for testing

		free(stacks.stack_a);
		free(stacks.stack_b);
		return (0);
	}
	return (0);
}
