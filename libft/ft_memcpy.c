/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:48:30 by dbouron           #+#    #+#             */
/*   Updated: 2021/11/12 20:44:44 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;
    char *source;
    char *destination;

    i = 0;
    source = (char *)src;
    destination = (char *)dst;
    if (source == 0 || destination == 0)
        return (0);
    while (i < n)
    {
        destination[i] = source[i];
        i++;
    }
    return (dst);
}