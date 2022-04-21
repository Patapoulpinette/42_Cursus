/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:20:52 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/21 21:47:51 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*indexing(t_data_stack stacks)
{
	int	i;
	int	j;
	int	count;
	int	*index;

	i = 0;
	index = malloc(sizeof(int *) * stacks.size_a);
	if (!index)
		return (NULL);
	while (i < stacks.size_a)
	{
		j = 0;
		count = 0;
		while (j < stacks.size_a)
		{
			if (stacks.stack_a[j] < stacks.stack_a[i])
				count++;
			j++;
		}
		index[i] = count;
		i++;
	}
	return (index);
}

bool	is_sorted(t_data_stack stacks)
{
	int	i;

	i = 0;
	while (i < stacks.size_a - 1 && stacks.stack_a[i] < stacks.stack_a [i + 1])
	{
		if (i == stacks.size_a - 1)
		{
			dprintf(2, "sorted");
			return (true);
		}
		i++;
	}
	return (false);
}

void	ft_algo_of_fire(t_data_stack stacks)//TODO test operations & algo
{
	int	i;
	int	j;

	i = 0;
	while (!is_sorted(stacks))
	{
		j = 0;
		while (j < stacks.size_a)
		{
			dprintf(2, "pouet\n");
			if ((stacks.stack_a[0] >> i) & 1)
			{
				dprintf(2, "if\n");
				rotate_a(stacks);
			}
			else
			{
				dprintf(2, "else\n");
				push_b(stacks);
				stacks.size_b++;//a enlever
				dprintf(2, "count = %d\n", stacks.size_b);
			}
			j++;
		}
		while (stacks.size_b > 0)
		{
			dprintf(2, "igloo\n");
			push_a(stacks);
			stacks.size_b--;//a enlever
		}
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