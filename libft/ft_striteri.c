/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:18:44 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/07 11:49:45 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/* void function(unsigned int i, char *a)
{
	if (i < ft_strlen(a))
		a[i] = a[i] - 32;
}

int main(void)
{
    char    *str;

    //void (*f)(unsigned int, char *) = &function;
    str = "bonjour";
	ft_striteri(str, &function);
    printf("str= %s\n", str);
    return (0);
} */