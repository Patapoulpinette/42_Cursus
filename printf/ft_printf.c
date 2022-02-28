/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:21:19 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/28 17:29:42 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	string_analyse(char *str, va_list ptr)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		while (str[i] != '%')
		{
			ft_putchar(str[i]);
			i++;
		}
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;

	va_start(ptr, str);
	string_analyse(str, ptr);
	va_end(ptr);
	//return ();
}