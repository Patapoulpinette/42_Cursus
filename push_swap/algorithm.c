/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:20:52 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/22 01:51:44 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>//for testing - usleep

bool	is_sorted(t_data_stack *stacks)//not working
{
	int	i;

	i = 0;
	while (i < stacks->size_a - 1 && stacks->stack_a[i] < stacks->stack_a[i + 1])
		i++;
	if (i == stacks->size_a - 1)
	{
		dprintf(2, "sorted\n");//for testing
		return (true);
	}
	else
	{
		dprintf(2, "not sorted\n");//for testing
		return (false);
	}
}

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
	return (index);
}

void	ft_algo_of_fire(t_data_stack *stacks)//TODO test algo : ne sort pas de la 1ere boucle qui demande si c'est trié
{
	int	i;
	int	j;
	int	k;//for testing
	int	l;//for testing

	i = 0;
	while (!is_sorted(stacks))
	{
		j = 0;
		while (j < stacks->size_a)
		{
			if ((stacks->stack_a[0] >> i) & 1)
			{
				rotate_a(stacks);
				k = 0;//for testing
				l = 0;//for testing
				dprintf(2, "rotate_a---------------\n");//for testing
				while (l < stacks->size_a)//for testing
					dprintf(2, "\t%d\n", stacks->stack_a[l++]);//for testing
				dprintf(2, "taille a = %d\n", stacks->size_a);//for testing
				while (k < stacks->size_b)//for testing
					dprintf(2, "\t%d\n", stacks->stack_b[k++]);//for testing
				dprintf(2, "taille b = %d\n", stacks->size_b);//for testing
			}
			else
			{
				push_b(stacks);
				k = 0;//for testing
				l = 0;//for testing
				dprintf(2, "push_b---------------\n");//for testing
				while (l < stacks->size_a)//for testing
					dprintf(2, "\t%d\n", stacks->stack_a[l++]);//for testing
				dprintf(2, "taille a = %d\n", stacks->size_a);//for testing
				while (k < stacks->size_b)//for testing
					dprintf(2, "\t%d\n", stacks->stack_b[k++]);//for testing
				dprintf(2, "taille b = %d\n", stacks->size_b);//for testing
			}
			j++;
		}
		while (stacks->size_b > 0)
		{
			push_a(stacks);
			k = 0;//for testing
			l = 0;//for testing
			dprintf(2, "push_a---------------\n");//for testing
			while (l < stacks->size_a)//for testing
				dprintf(2, "\t%d\n", stacks->stack_a[l++]);//for testing
			dprintf(2, "taille a = %d\n", stacks->size_a);//for testing
			while (k < stacks->size_b)//for testing
				dprintf(2, "\t%d\n", stacks->stack_b[k++]);//for testing
			dprintf(2, "taille b = %d\n", stacks->size_b);//for testing
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