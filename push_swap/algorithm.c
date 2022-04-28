/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:20:52 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/28 11:00:45 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	search_smaller_nbr(t_data_stack *stacks)
{
	int	i;
	int	j;
	int	smaller_index;

	i = 0;
	j = 1;
	while (i < stacks->size_a && j < stacks->size_a)
	{
		if (stacks->stack_a[i] < stacks->stack_a[j])
			smaller_index = i;
		else
			smaller_index = j;
		i = smaller_index;
		j++;
	}
	return (smaller_index);
}

void	sorting_3nbrs(t_data_stack *stacks)
{
	while (!is_sorted(stacks))
	{
		if (stacks->stack_a[0] < stacks->stack_a[2] \
			&& stacks->stack_a[2] < stacks->stack_a[1])
		{
			swap_a(stacks, 1);
			rotate_a(stacks, 1);
		}
		else if (stacks->stack_a[1] < stacks->stack_a[0] \
			&& stacks->stack_a[0] < stacks->stack_a[2])
			swap_a(stacks, 1);
		else if (stacks->stack_a[2] < stacks->stack_a[0] \
			&& stacks->stack_a[0] < stacks->stack_a[1])
			reverse_rotate_a(stacks, 1);
		else if (stacks->stack_a[1] < stacks->stack_a[2] \
			&& stacks->stack_a[2] < stacks->stack_a[0])
			rotate_a(stacks, 1);
		else if (stacks->stack_a[2] < stacks->stack_a[1] \
			&& stacks->stack_a[1] < stacks->stack_a[0])
		{
			swap_a(stacks, 1);
			reverse_rotate_a(stacks, 1);
		}
	}
}

void	sorting_5nbrs(t_data_stack *stacks)
{
	int	smaller_index;

	while (!is_sorted(stacks))
	{
		while (stacks->size_a > 3)
		{
			smaller_index = search_smaller_nbr(stacks);
			while (smaller_index != 0 && smaller_index != stacks->size_a)
			{
				if (smaller_index <= stacks->size_a / 2)
					rotate_a(stacks, 1);
				else
					reverse_rotate_a(stacks, 1);
				smaller_index = search_smaller_nbr(stacks);
			}
			push_b(stacks);
		}
		sorting_3nbrs(stacks);
		push_a(stacks);
		push_a(stacks);
	}
}

void	sorting_radix(t_data_stack *stacks)
{
	int	i;
	int	j;
	int	size_a_init;

	i = 0;
	size_a_init = stacks->size_a;
	stacks->stack_a = indexing(stacks);
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
