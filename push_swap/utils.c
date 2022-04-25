/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:04:29 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/25 16:48:05 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
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

long	ft_atol(const char *str)
{
	int		i;
	long	neg;
	long	result;

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

bool	is_sorted(t_data_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size_a - 1 \
			&& stacks->stack_a[i] < stacks->stack_a[i + 1])
		i++;
	if (i == stacks->size_a - 1)
	{
		dprintf(2, "sorted \033[1;32m✔\033[0m\n");//for testing
		return (true);
	}
	else
	{
		//dprintf(2, "not sorted \033[1;31m✗\033[0m\n");//for testing
		return (false);
	}
}
