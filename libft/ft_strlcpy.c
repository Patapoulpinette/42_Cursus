/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:49:01 by dbouron           #+#    #+#             */
/*   Updated: 2021/11/12 17:49:02 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
    size_t  i;

    i = 0;
    if (dstsize == 0)
        return (ft_strlen(src));
    else
    {
        while (i < ft_strlen(src) && i < dstsize - 1)
        {
            dst[i] = src[i];
            i++;
        }
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}
