/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:16:16 by dbouron           #+#    #+#             */
/*   Updated: 2021/11/15 01:02:07 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;
	unsigned int	j;

	i = start;
	j = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (0);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (s[i] && i < (start + len))
	{
		result[j] = s[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}
