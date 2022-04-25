/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:44:39 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/25 18:27:05 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_data_stack *stacks)
{
	int	i;

	i = 0;
	if (stacks->size_b == 0)
		return ;
	while (i < stacks->size_a)
		i++;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = stacks->stack_b[0];
	i = 0;
	while (i < stacks->size_b)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->size_a++;
	stacks->size_b--;
	write(1, "pa\n", 3);
}

void	push_b(t_data_stack *stacks)
{
	int	i;

	i = 0;
	if (stacks->size_a == 0)
		return ;
	while (i < stacks->size_b)
		i++;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = stacks->stack_a[0];
	i = 0;
	while (i < stacks->size_a)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->size_a--;
	stacks->size_b++;
	write(1, "pb\n", 3);
}
