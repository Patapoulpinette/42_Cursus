/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:23:56 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/07 10:36:08 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rotate_a(char *str)
{
	char	temp;
	int		i;

	i = 0;
	if (!str)
		return ;
	temp = str[0];
	while (str[i])
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = temp;
}

void	rotate_b(char *str)
{
	char	temp;
	int		i;

	i = 0;
	if (!str)
		return ;
	temp = str[0];
	while (str[i])
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = temp;
}

void	rotate_ab(char *str_a, char *str_b)
{
	rotate_a(str_a);
	rotate_b(str_b);
}
