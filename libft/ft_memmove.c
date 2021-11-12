/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:48:36 by dbouron           #+#    #+#             */
/*   Updated: 2021/11/12 20:49:35 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t  i;
    char    *source;
    char    *dest;

    i = 0;
    source = (char *)src;
    dest = (char *)dst;
    if (dest < source)
    {
        while (i < len)
        {
            dest[i] = source [i];
            i++;
        }
    }
    else if (source < dest)
    {
        while (len > 0)
        {
            dest[len - 1] = source[len - 1];
            len--;
        }
    }
    return (dst);
}
