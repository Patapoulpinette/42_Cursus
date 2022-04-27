/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:41:09 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/26 11:38:48 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initializing(int argc, t_data_stack *stacks)
{
	stacks->size_a = argc - 1;
	stacks->size_b = 0;
	stacks->stack_a = malloc(sizeof(int *) * stacks->size_a);
	stacks->stack_b = malloc(sizeof(int *) * stacks->size_a);
}

void	free_to_quit(t_data_stack *stacks)
{
	free(stacks->stack_a);
	free(stacks->stack_b);
}

int	main(int argc, char **argv)
{
	int				i;
	int				j;
	t_data_stack	stacks;

	if (parsing(argc, argv) == 0)
	{
		i = 1;
		j = 0;
		initializing(argc, &stacks);
		if (!stacks.stack_a || !stacks.stack_b)
			return (0);
		while (argv[i] && i < argc)
			stacks.stack_a[j++] = ft_atoi(argv[i++]);
		if (stacks.size_a == 2 && !is_sorted(&stacks))
			swap_a(&stacks, 1);
		else if (stacks.size_a == 3)
			sorting_3nbrs(&stacks);
		else if (stacks.size_a <= 5)
			sorting_5nbrs(&stacks);
		else
			sorting_radix(&stacks);
		free_to_quit(&stacks);
		return (0);
	}
	return (0);
}
