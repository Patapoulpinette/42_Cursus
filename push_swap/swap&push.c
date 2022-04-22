/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap&push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:22:10 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/22 12:34:25 by dbouron          ###   ########.fr       */
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
		/*ft_*/printf("sa\n");
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
		/*ft_*/printf("sb\n");
}

void	swap_ab(t_data_stack *stacks)
{
	swap_a(stacks, 0);
	swap_b(stacks, 0);
	/*ft_*/printf("ss\n");
}

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
	/*ft_*/printf("pa\n");
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
	/*ft_*/printf("pb\n");
}
