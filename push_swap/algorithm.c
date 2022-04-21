/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:20:52 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/21 18:31:38 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
//
//void	tri_rapide(int *tableau, int taille)
//{
//	int mur, courant, pivot, tmp;
//
//	if (taille < 2) return;
//	// On prend comme pivot l element le plus a droite
//	pivot = tableau[taille - 1];
//	mur = courant = 0;
//	while (courant < taille)
//	{
//		if (tableau[courant] <= pivot)
//		{
//			if (mur != courant)
//			{
//				tmp = tableau[courant];
//				tableau[courant] = tableau[mur];
//				tableau[mur] = tmp;
//			}
//			mur ++;
//		}
//		courant ++;
//	}
//	tri_rapide(tableau, mur - 1);
//	tri_rapide(tableau + mur - 1, taille - mur + 1);
//}

int	*indexing(int *tab, int size)
{
	int	i;
	int	j;
	int	count;
	int	*index;

	i = 0;
	index = malloc(sizeof(int *) * size);
	if (!index)
		return (NULL);
	while (i < size)
	{
		j = 0;
		count = 0;
		while (j < size)
		{
			if (tab[j] < tab[i])
				count++;
			j++;
		}
		index[i] = count;
		i++;
	}
	return (index);
}

bool	is_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1 && tab[i] < tab [i + 1])
	{
		if (i == size - 1)
		{
			dprintf(2, "sorted");
			return (true);
		}
		i++;
	}
	return (false);
}

void	ft_algo_of_fire(int *stack_a, int *stack_b, int size_a)//TODO test operations & algo
{
	int	i;
	int	j;
	int	size_b;

	i = 0;
	size_b = 0;
	while (!is_sorted(stack_a, size_a))
	{
		j = 0;
		while (j < size_a)
		{
			dprintf(2, "pouet\n");
			if ((stack_a[0] >> i) & 1)
			{
				dprintf(2, "if\n");
				rotate_a(stack_a, size_a);
			}
			else
			{
				dprintf(2, "else\n");
				push_b(stack_a, stack_b, size_a, size_b);
				size_b++;
				dprintf(2, "count = %d\n", count);
			}
			j++;
		}
		while (size_b > 0)
		{
			dprintf(2, "igloo\n");
			push_a(stack_a, stack_b, size_a, size_b);
			size_b--;
		}
		i++;
	}

}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	*tab_a;
	int	*tab_b;

	i = 1;
	j = 0;
	tab_a = malloc(sizeof(int *) * argc - 1);
	tab_b = malloc(sizeof(int *) * argc - 1);
	if (!tab_a || !tab_b)
		return (0);
	while (argv[i] && i < argc)
	{
		tab_a[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	tab_a = indexing(tab_a, argc - 1);
	ft_algo_of_fire(tab_a, tab_b, argc - 1);
	j = 0;
	while (j < argc - 1)
		dprintf(2, "%d\n", tab_a[j++]);
	free(tab_a);
	free(tab_b);
	return (0);
}
