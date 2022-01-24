/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:14:14 by dbouron           #+#    #+#             */
/*   Updated: 2022/01/18 17:07:14 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_nbword(char const *s, char c)
{
    size_t  i;
    size_t  nbword;
    
    i = 0;
    while (s[i])
    {
        nbword = 0;
        if (s[i] == c)
        {
            nbword++;
            i++;
        }
        i++;
    }
}

char    **ft_split(char const *s, char c)
{
    char    **tab;
    size_t  nbword;

    nbword = ft_nbword;
    // Mallocage du tableau
    tab = malloc(sizeof(char) * ft_nbword);
    if (!tab)
        return (NULL);
    
    // Mallocage des strings
}