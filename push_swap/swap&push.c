/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap&push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:22:10 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/07 10:41:29 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_a(char *str)
{
	char	temp;

	if (!str)
		return ;
	temp = str[0];
	str[0] = str[1];
	str[1] = temp;
}

void	swap_b(char *str)
{
	char	temp;

	if (!str)
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
