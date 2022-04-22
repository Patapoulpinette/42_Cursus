/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:37:26 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/22 12:34:25 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_data_stack *stacks, int mode)
{
	int	i;
	int	temp;

	i = 0;
	while (i < stacks->size_a)
		i++;
	temp = stacks->stack_a[i - 1];
	while (i > 1)
	{
		stacks->stack_a[i - 1] = stacks->stack_a[i - 2];
		i--;
	}
	stacks->stack_a[0] = temp;
	if (mode)
		/*ft_*/printf("rra\n");
}

void	reverse_rotate_b(t_data_stack *stacks, int mode)
{
	int	i;
	int	temp;

	i = 0;
	while (i < stacks->size_b)
		i++;
	temp = stacks->stack_b[i - 1];
	while (i > 1)
	{
		stacks->stack_b[i - 1] = stacks->stack_b[i - 2];
		i--;
	}
	stacks->stack_b[0] = temp;
	if (mode)
		/*ft_*/printf("rrb\n");
}

void	reverse_rotate_ab(t_data_stack *stacks)
{
	reverse_rotate_a(stacks, 0);
	reverse_rotate_b(stacks, 0);
	/*ft_*/printf("rrr\n");
}
