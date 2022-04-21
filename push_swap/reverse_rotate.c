/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:37:26 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/21 18:25:59 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	reverse_rotate_a(int *stack_a, int size_a)
{
	int		i;
	char	temp;

	i = 0;
	while (i < size_a)
		i++;
	temp = stack_a[i - 1];
	while (i > 1)
	{
		stack_a[i - 1] = stack_a[i - 2];
		i--;
	}
	stack_a[0] = temp;
}

void	reverse_rotate_b(int *stack_b, int size_b)
{
	int		i;
	char	temp;

	i = 0;
	while (i < size_b)
		i++;
	temp = stack_b[i - 1];
	while (i > 1)
	{
		stack_b[i - 1] = stack_b[i - 2];
		i--;
	}
	stack_b[0] = temp;
}

void	reverse_rotate_ab(int *stack_a, int *stack_b, int size_a, int size_b)
{
	reverse_rotate_a(stack_a, int size_a);
	reverse_rotate_b(stack_b, int size_b);
}
