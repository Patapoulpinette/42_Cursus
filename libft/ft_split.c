/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:14:14 by dbouron           #+#    #+#             */
/*   Updated: 2022/01/28 20:57:45 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbword(char const *s, char c)
{
	size_t	check;
	size_t	i;
	size_t	nbword;

	i = 0;
	nbword = 0;
	while (s[i])
	{
		check = 0;
		while (s[i] != c)
		{
			check++;
			i++;
		}
		if (check > 0)
			nbword++;
		i++;
	}
	return (nbword);
}

size_t	ft_nbchar(char const *s, char c)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = start;
	//dans le but de faire un substr
	while (s[start])
	{
		while (s[start] == c)
			start++;
		while (s[end] != c)
			end++;
	}
	return (end - start);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	nbword;
	size_t	i;

	i = 0;
	nbword = ft_nbword(s, c); 
	
	// Mallocage du tableau
	tab = malloc(sizeof(char) * nbword);
	if (!tab)
		return (NULL);

	// Mallocage des strings
	while (i <= nbword)
	{
		tab[i] = malloc(sizeof(char) * ft_nbchar(s, c));
		if (!tab[i])
			return (NULL);
	}
	return (tab);
}


#include <stdio.h>

int main(void)
{
	char	*string;

	string = "Je suis une truite";
	printf("%zu", ft_nbword(string, ' '));
	return (0);
}