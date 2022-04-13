/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:41:09 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/13 14:44:00 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(int argc, char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (*tab[j] && j < argc - 1)
	{
		while (tab[j][i])
		{
			if (ft_isdigit(tab[j][i]) == 0)
				return (/*ft_*/printf("Error | %c\n", tab[j][i]));
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	parsing(argc, argv);
//	algorythm
	return (0);
}
