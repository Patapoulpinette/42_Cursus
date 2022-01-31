/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:14:14 by dbouron           #+#    #+#             */
/*   Updated: 2022/01/31 18:30:10 by dbouron          ###   ########lyon.fr   */
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
	while (s[i] && i < ft_strlen(s))
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
		start = end;
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		tab[i] = malloc(sizeof(char) * ((end - start) + 1));
		if (!tab[i++])
			return (0);
		start++;
		end++;
	}
	tab[i] = malloc(sizeof(char) * ((end - start) + 1));
	if (!tab[i])
		return (0);
	return (1);
}

size_t	ft_fillingtab(char const *s, char c, char **tab)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = 0;
	i = 0;
	while (s[start] && s[end])
	{
		start = end;
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		tab[i] = ft_substr(s, (unsigned int)start, (end - start));
		start++;
		end++;
		i++;
	}
	tab[i][0] = '\0';
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;

	tab = malloc(sizeof(char) * (ft_nbword(s, c) + 1));
	if (!tab)
		return (NULL);
	if (ft_mallocstr(s, c, tab) == 0)
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
	ft_fillingtab(s, c, tab);
	return (tab);
}
/* 

int main(void)
{
	char	*string;
	size_t	nbword;
	char	**result;
	int		i;

	string = "Je suis une patapoulpinette";
	i = 0;
	nbword = ft_nbword(string, 'e');
	printf("%zu \n", nbword);
	result = ft_split(string, 'e');
	if (!result)
		return (0);
	while (i < nbword)
	{
		printf("%s \n", result[i]);
		i++;
	}
	return (0);
} */