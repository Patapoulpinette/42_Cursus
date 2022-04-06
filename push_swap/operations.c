/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:27:34 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/06 16:33:51 by dbouron          ###   ########.fr       */
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
	if (!str_b)
		return ;

}
