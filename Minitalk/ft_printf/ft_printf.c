/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:21:19 by dbouron           #+#    #+#             */
/*   Updated: 2022/03/07 10:03:34 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(char c, va_list ptr)
{
	int	l;

	if (c == 'c')
		l = ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		l = ft_putstr(va_arg(ptr, char *));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		l = ft_putnb_b_ull(va_arg(ptr, unsigned long long), "0123456789abcdef");
		l = l + 2;
	}
	else if (c == 'd' || c == 'i')
		l = ft_putnbr(va_arg(ptr, int));
	else if (c == 'u')
		l = ft_putnb_b_ui(va_arg(ptr, unsigned int), "0123456789");
	else if (c == 'x')
		l = ft_putnb_b_ui(va_arg(ptr, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		l = ft_putnb_b_ui(va_arg(ptr, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		l = ft_putchar('%');
	else
		l = ft_putchar(c);
	return (l);
}

int	string_analyse(const char *str, va_list ptr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
		return (i);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += conversion(str[i + 1], ptr);
			i++;
		}
		else if (str[i] != '%')
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;

	va_start(ptr, str);
	len = string_analyse(str, ptr);
	va_end(ptr);
	return (len);
}
