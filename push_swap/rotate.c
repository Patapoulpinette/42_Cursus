/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:23:56 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/21 18:23:47 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rotate_a(int *stack_a, int size_a)
{
	char	temp;
	int		i;

	i = 0;
	if (size_a == 0)
		return ;
	temp = stack_a[0];
	while (i < size_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i - 1] = temp;
}

void	rotate_b(int *stack_b, int size_b)
{
	char	temp;
	int		i;

	i = 0;
	if (size_b == 0)
		return ;
	temp = stack_b[0];
	while (i < size_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i - 1] = temp;
}

void	rotate_ab(int *stack_a, int *stack_b, int size_a, int size_b)
{
	rotate_a(stack_a, int size_a);
	rotate_b(stack_b, int size_b);
}
