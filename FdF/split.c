/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:41:49 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/21 21:08:15 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_nbword(char const *s, char c)
{
	size_t	check;
	size_t	i;
	size_t	nbword;

	i = 0;
	nbword = 0;
	while (i < ft_strlen(s) && s[i])
	{
		check = 0;
		while (s[i] != c && s[i])
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

static size_t	ft_fillingtab(char const *s, char c, char **tab)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = 0;
	i = 0;
	while (s[end] && i < ft_nbword(s, c))
	{
		start = end;
		while (s[start] == c && s[start])
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		tab[i] = ft_substr(s, (unsigned int)start, (end - start));
		if (!tab[i])
			return (0);
		i++;
	}
	tab[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;

	tab = ft_calloc(sizeof(char *), (ft_nbword(s, c) + 1));
	if (!tab)
		return (NULL);
	if (!(ft_fillingtab(s, c, tab)))
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		return (NULL);
	}
	return (tab);
}
