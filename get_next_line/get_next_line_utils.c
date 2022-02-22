/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:38:15 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/22 19:06:07 by dbouron          ###   ########lyon.fr   */
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
		result = ft_calloc((len + 1), sizeof(char));
	else
		result = ft_calloc((ft_strlen(s) - start + 1), sizeof(char));
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	result = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
	if (s2)
		while (s2[j])
			result[i++] = s2[j++];
	result[i] = 0;
	free(s1);
	return (result);
}

void	*ft_calloc(size_t count, size_t type_size)
{
	void	*result;
	size_t	i;
	char	*str;

	result = malloc(count * type_size);
	if (!result)
		return (NULL);
	i = 0;
	str = (char *)result;
	while (i < count * type_size)
	{
		str[i] = 0;
		i++;
	}
	return (result);
}
