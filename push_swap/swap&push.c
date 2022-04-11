/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap&push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:22:10 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/11 11:49:38 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap_a(char *str)
{
	char	temp;

	if (!str || !str[1])
		return ;
	temp = str[0];
	str[0] = str[1];
	str[1] = temp;
}

void	swap_b(char *str)
{
	char	temp;

	if (!str || !str[1])
		return ;
	temp = str[0];
	str[0] = str[1];
	str[1] = temp;
}

void	swap_stack(char *str_a, char *str_b)
{
	swap_a(str_a);
	swap_b(str_b);
}

void	push_a(char *str_a, char *str_b)
{
	int	i;

	i = 0;
	if (!str_b)
		return ;
	while (str_a[i])
		i++;
	while (i > 0)
	{
		str_a[i] = str_a[i - 1];
		i--;
	}
	str_a[0] = str_b[0];
	i = 0;
	while (str_b[i])
	{
		str_b[i] = str_b[i + 1];
		i++;
	}
}

void	push_b(char *str_a, char *str_b)
{
	int	i;

	i = 0;
	if (!str_a)
		return ;
	while (str_b[i])
		i++;
	while (i > 0)
	{
		str_b[i] = str_b[i - 1];
		i--;
	}
	str_b[0] = str_a[0];
	i = 0;
	while (str_a[i])
	{
		str_a[i] = str_a[i + 1];
		i++;
	}
}

int	main(void)
{
	char	a[15] = "123456789";
	char	b[5] = "023";

	dprintf(2, "a : %s\nb : %s\n", a, b);
	swap_stack(a, b);
	dprintf(2, "a : %s\nb : %s\n", a, b);
	push_a(a, b);
	dprintf(2, "a : %s\nb : %s\n", a, b);
	swap_stack(a, b);
	dprintf(2, "a : %s\nb : %s\n", a, b);
	push_a(a, b);
	dprintf(2, "a : %s\nb : %s\n", a, b);
	return (0);
}