/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:37:54 by dbouron           #+#    #+#             */
/*   Updated: 2022/05/20 13:54:29 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
