/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:37:26 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/11 12:22:05 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	reverse_rotate_a(char *str)
{
	int		i;
	char	temp;

	i = 0;
	while (str[i])
		i++;
	temp = str[i - 1];
	while (i > 1)
	{
		str[i - 1] = str[i - 2];
		i--;
	}
	str[0] = temp;
}

void	reverse_rotate_b(char *str)
{
	int		i;
	char	temp;

	i = 0;
	while (str[i])
		i++;
	temp = str[i - 1];
	while (i > 1)
	{
		str[i - 1] = str[i - 2];
		i--;
	}
	str[0] = temp;
}

void	reverse_rotate_ab(char *str_a, char *str_b)
{
	reverse_rotate_a(str_a);
	reverse_rotate_b(str_b);
}

int	main(void)
{
	char	a[10] = "123456789";
	char	b[4] = "987";

	dprintf(2, "a : %s\nb : %s\n", a, b);
	reverse_rotate_ab(a, b);
	dprintf(2, "a : %s\nb : %s\n", a, b);
}