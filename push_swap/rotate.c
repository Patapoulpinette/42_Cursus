/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:23:56 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/22 12:34:25 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data_stack *stacks, int mode)
{
	int	temp;
	int	i;

	i = 0;
	if (stacks->size_a == 0)
		return ;
	temp = stacks->stack_a[0];
	while (i < stacks->size_a)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[i - 1] = temp;
	if (mode)
		/*ft_*/printf("ra\n");
}

void	rotate_b(t_data_stack *stacks, int mode)
{
	int	temp;
	int	i;

	i = 0;
	if (stacks->size_b == 0)
		return ;
	temp = stacks->stack_b[0];
	while (i < stacks->size_b)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[i - 1] = temp;
	if (mode)
		/*ft_*/printf("rb\n");
}

void	rotate_ab(t_data_stack *stacks)
{
	rotate_a(stacks, 0);
	rotate_b(stacks, 0);
	/*ft_*/printf("rr\n");
}
