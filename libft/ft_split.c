/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:14:14 by dbouron           #+#    #+#             */
/*   Updated: 2022/01/30 17:56:04 by dbouron          ###   ########lyon.fr   */
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

size_t	ft_mallocstr(char const *s, char c, char **tab)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = 0;
	i = 0;
	while (s[start] && s[end])
	{
		//comptage des chars
		start = end;
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		//mallocage des strings
		tab[i] = malloc(sizeof(char) * ((end - start) + 1));
		if (!tab[i])
			return (0);
		start++;
		end++;
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	nbword;
	size_t	i;

	i = 0;
	nbword = ft_nbword(s, c); 
	
	// Mallocage du tableau
	tab = malloc(sizeof(char) * (nbword + 1));
	if (!tab)
		return (NULL);

	// Mallocage des strings

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