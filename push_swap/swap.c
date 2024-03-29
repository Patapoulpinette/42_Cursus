/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap&push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:22:10 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/25 17:47:09 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data_stack *stacks, int mode)
{
	int	temp;

	if (stacks->size_a < 2)
		return ;
	temp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = temp;
	if (mode)
		write(1, "sa\n", 3);
}

void	swap_b(t_data_stack *stacks, int mode)
{
	int	temp;

	if (stacks->size_b < 2)
		return ;
	temp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = temp;
	if (mode)
		write(1, "sb\n", 3);
}

void	swap_ab(t_data_stack *stacks)
{
	swap_a(stacks, 0);
	swap_b(stacks, 0);
	write(1, "ss\n", 3);
}
