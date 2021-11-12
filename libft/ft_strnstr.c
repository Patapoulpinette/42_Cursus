/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:13:10 by dbouron           #+#    #+#             */
/*   Updated: 2021/11/12 16:51:11 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	pinpoint;

	i = 0;
	if (needle[0] == '\0')
		return (haystack);
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			pinpoint = i;
			while (haystack[i] == needle[j] && j < len)
			{
				if (needle[j + 1] == '\0' || j == len - 1)
					return (&haystack[pinpoint]);
				i++;
				j++;
			}
			i = pinpoint;
		}
		i++;
	}
	return (0);
}