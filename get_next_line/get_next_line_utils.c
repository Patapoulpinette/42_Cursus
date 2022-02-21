/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:38:15 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/21 19:50:33 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_mystrchr(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = NULL;
	i = start;
	j = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (0);
	if (ft_strlen(s) > len)
		result = malloc(sizeof(char) * (len + 1));
	else
		result = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!result)
		return (NULL);
	while (s[i] && i < (start + len))
		result[j++] = s[i++];
	result[j] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

// static char	*ft_join_s2(char const *s2)
// {
// 	char	*result;
// 	size_t	i;

// 	result = malloc(sizeof(char) * (ft_strlen(s2) + 1));
// 	if (!result)
// 		return (NULL);
// 	i = 0;
// 	while (s2[i])
// 	{
// 		result[i] = s2[i];
// 		i++;
// 	}
// 	result[i] = '\0';
// 	return (result);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*result;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (!s1)
// 	{
// 		return (ft_join_s2(s2));
// 	}
// 	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!result)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		result[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j])
// 		result[i++] = s2[j++];
// 	result[i] = '\0';
// 	free((void *)s1);
// 	return (result);
// }

//------------------------------------------------------
char *ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	puts("HELLO");
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	puts("HELLO 1");
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
	puts("HELLO 2");
	puts(s2);
	if (s2)
		while (s2[j])
			result[i++] = s1[j++];
	puts("HELLO 3");
	result[i] = 0;
	free(s1);
	puts("HELLO 4");
	return (result);
}