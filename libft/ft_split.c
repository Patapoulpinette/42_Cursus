/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:14:14 by dbouron           #+#    #+#             */
/*   Updated: 2022/01/24 17:47:33 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_nbword(char const *s, char c)
{
    size_t  i;
    size_t  nbword;
    
    i = 0;
	nbword = 0;
    while (s[i])
    {
        if (s[i] == c && s[i + 1] != c)
            nbword++;
        i++;
    }
	return (nbword + 1);
}

char    **ft_split(char const *s, char c)
{
    char    **tab;
    size_t  nbword;

    nbword = ft_nbword;
    // Mallocage du tableau
    tab = malloc(sizeof(char) * ft_nbword(s, c));
    if (!tab)
        return (NULL);
    
    // Mallocage des strings
}