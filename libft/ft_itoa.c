/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:16:41 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/04 17:39:44 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	unsigned int	nb;
	int				len;

	if (n < 0)
	{
		n = n * -1;
		len = 1;
	}
	nb = n;
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_intlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0 && len >= 0)
	{
		//n = n / 10;
		//str[len] = '0' + i % 10;
		//len--;
	}
	return (str);
}


/* int main(void)
{
	int	n;

	n = 0;
	printf("%d\n", ft_intlen(n));
	printf("%s", ft_itoa(n));
	return (0);
} */


/* 	void	ft_putnbr(int nb)
{
	unsigned int	i;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	i = nb;
	if (i > 9)
	{
		ft_putnbr(i / 10);
	}
	ft_putchar('0' + i % 10);
} */