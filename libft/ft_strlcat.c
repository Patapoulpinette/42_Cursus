/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:48:57 by dbouron           #+#    #+#             */
/*   Updated: 2021/11/12 17:48:58 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = ft_strlen(dst);
    if (dstsize == 0)
        return (ft_strlen(src));
    else
    {
        while (j < dstsize - 1)
        {
            dst[j] = src[i];
            i++;
            j++;
        }
    }
    dst[j] = '\0';
    return (ft_strlen(src));
}