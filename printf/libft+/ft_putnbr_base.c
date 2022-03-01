/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:54:17 by dbouron           #+#    #+#             */
/*   Updated: 2022/03/01 16:06:15 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_error(char *base)
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

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	ui;

	if (ft_error(base) == 0)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = nbr * -1;
		}
		ui = nbr;
		if (ui > ft_strlen(base) - 1)
			ft_putnbr_base(ui / ft_strlen(base), base);
		ft_putchar(base[ui % ft_strlen(base)]);
	}
}
