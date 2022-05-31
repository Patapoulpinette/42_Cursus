/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:37:54 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/23 18:06:08 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result != 0)
			result = result * 10;
		result = result + (str[i] - 48);
		i++;
	}
	return (result * neg);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
	}
	if (s2)
		while (s2[j])
			result[i++] = s2[j++];
	result[i] = 0;
	free(s1);
	return (result);
}
