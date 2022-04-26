/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:04:29 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/26 10:46:24 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_intlen(int n)
{
	unsigned int	nb;
	int				len;

	len = 0;
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result != 0)
			result = result * 10;
		result = result + (str[i] - 48);
		i++;
	}
	return (result * neg);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	int				len;

	len = ft_intlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	nb = n;
	while (nb > 0 && len >= 0)
	{
		str[len--] = '0' + nb % 10;
		nb = nb / 10;
	}
	return (str);
}

bool	is_sorted(t_data_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size_a - 1 \
			&& stacks->stack_a[i] < stacks->stack_a[i + 1])
		i++;
	if (i == stacks->size_a - 1)
		return (true);
	else
		return (false);
}
