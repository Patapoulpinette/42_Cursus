/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:20:52 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/22 15:18:31 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_data_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size_a - 1 \
			&& stacks->stack_a[i] < stacks->stack_a[i + 1])
		i++;
	if (i == stacks->size_a - 1)
	{
		dprintf(2, "sorted \033[1;32m✔\033[0m\n");//for testing
		return (true);
	}
	else
	{
		dprintf(2, "not sorted \033[1;31m✗\033[0m\n");//for testing
		return (false);
	}
}

int	*indexing(t_data_stack *stacks)
{
	int	i;
	int	j;
	int	count;
	int	*index;

	i = 0;
	index = malloc(sizeof(int *) * stacks->size_a);
	if (!index)
		return (NULL);
	while (i < stacks->size_a)
	{
		j = 0;
		count = 0;
		while (j < stacks->size_a)
		{
			if (stacks->stack_a[j] < stacks->stack_a[i])
				count++;
			j++;
		}
		index[i] = count;
		i++;
	}
	free(stacks->stack_a);
	return (index);
}

void	ft_algorithm(t_data_stack *stacks)
{
	int	i;
	int	j;
	int	size_a_init;

	i = 0;
	size_a_init = stacks->size_a;
	while (!is_sorted(stacks))
	{
		j = 0;
		while (j < size_a_init)
		{
			if ((stacks->stack_a[0] >> i) & 1)
				rotate_a(stacks, 1);
			else
				push_b(stacks);
			j++;
		}
		while (stacks->size_b > 0)
			push_a(stacks);
		i++;
	}
}

//______________________________________________________________________________
//
//void	algorithm(int size, int *stack_a)
//{
//	int	wall;
//	int	current;
//	int	pivot;
//	int	tmp;
//
//	if (size < 2)
//		return ;
//	pivot = stack_a[size - 1];
//	wall = 0;
//	current = 0;
//	while (current < size)
//	{
//		if (stack_a[current] <= pivot)
//		{
//			if (wall != current)
//			{
//				tmp = stack_a[current];
//				stack_a[current] = stack_a[wall];
//				stack_a[wall] = tmp;
//			}
//			wall++;
//		}
//		current++;
//	}
//	algorithm(wall - 1, stack_a);
//	algorithm(size - wall + 1, stack_a + wall - 1);
//}