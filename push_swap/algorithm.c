/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:20:52 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/20 12:02:36 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(int argc, char **argv)
{

}

void	tri_rapide(int *tableau, int taille)
{
	int mur, courant, pivot, tmp;

	if (taille < 2) return;
	// On prend comme pivot l element le plus a droite
	pivot = tableau[taille - 1];
	mur = courant = 0;
	while (courant < taille)
	{
		if (tableau[courant] <= pivot)
		{
			if (mur != courant)
			{
				tmp = tableau[courant];
				tableau[courant] = tableau[mur];
				tableau[mur] = tmp;
			}
			mur ++;
		}
		courant ++;
	}
	tri_rapide(tableau, mur - 1);
	tri_rapide(tableau + mur - 1, taille - mur + 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	*tab;

	i = 1;
	j = 0;
	tab = malloc(sizeof(int *) * argc);
	while (argv[i] && i < argc)
	{
		tab[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	tri_rapide(tab, argc);
	j = 0;
	while (j < argc - 1)
		dprintf(2, "%d\n", tab[j++]);
	return (0);
}
