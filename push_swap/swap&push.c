/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap&push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:22:10 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/21 18:20:54 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_a(int *stack_a, int size_a)
{
	char	temp;

	if (size_a < 2)
		return ;
	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
}

void	swap_b(int *stack_b, int size_b)
{
	char	temp;

	if (size_b < 2)
		return ;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
}

void	swap_ab(int *stack_a, int *stack_b, int size_a, int size_b)
{
	swap_a(stack_a, size_a);
	swap_b(stack_b, size_b);
}

void	push_a(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	i;

	i = 0;
	if (size_b == 0)
		return ;
	while (i < size_a)
		i++;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	i = 0;
	while (i < size_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
}

void	push_b(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	i;

	i = 0;
	if (size_a == 0)
		return ;
	while (i < size_b)
		i++;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	i = 0;
	while (i < size_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
}
