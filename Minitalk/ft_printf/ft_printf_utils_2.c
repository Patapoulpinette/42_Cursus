/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:34:31 by dbouron           #+#    #+#             */
/*   Updated: 2022/03/04 15:39:36 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_intlen(int nb)
{
	size_t			len;
	unsigned int	nbr;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb = nb * -1;
	}
	nbr = nb;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		len++;
	}
	len++;
	return (len);
}

int	ft_putnbr(int nb)
{
	unsigned int	i;
	int				len;

	len = ft_intlen(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	i = nb;
	if (i > 9)
	{
		ft_putnbr(i / 10);
	}
	ft_putchar('0' + i % 10);
	return (len);
}

static int	ft_error(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] != base[j])
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_putnb_b_ui(unsigned int nbr, char *base)
{
	int	len;

	len = 0;
	if (ft_error(base) == 0)
	{
		if (nbr > ft_strlen(base) - 1)
			len += ft_putnb_b_ui(nbr / ft_strlen(base), base);
		len += ft_putchar(base[nbr % ft_strlen(base)]);
	}
	return (len);
}

int	ft_putnb_b_ull(unsigned long long nbr, char *base)
{
	int	len;

	len = 0;
	if (ft_error(base) == 0)
	{
		if (nbr > ft_strlen(base) - 1)
			len += ft_putnb_b_ull(nbr / ft_strlen(base), base);
		len += ft_putchar(base[nbr % ft_strlen(base)]);
	}
	return (len);
}
