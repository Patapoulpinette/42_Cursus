/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:21:19 by dbouron           #+#    #+#             */
/*   Updated: 2022/03/01 15:14:52 by dbouron          ###   ########lyon.fr   */
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
	while (str[i] != '%' && str[i])
	{
		if (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 's' || \
			str[i + 1] == 'p' || str[i + 1] == 'd' || str[i + 1] == 'i' || \
			str[i + 1] == 'u' || str[i + 1] == 'x' || str[i + 1] == 'X' || \
			str[i + 1] == '%'))
		{
			conversion(str[i + 1], ptr);
			i = i + 2;
		}
		else if (str[i] == '%' && str[i + 1] == '\0')
			i++;
		else if (str[i] != '%')
		{
			ft_putchar(str[i]);
			i++;
		}
		i++;
	}
}

void	conversion(char c, va_list ptr)
{
	if (c == 'c')
		ft_putchar(va_arg(ptr, char));
	if (c == 's')
		ft_putstr(va_arg(ptr, char *));
	/* if (c == 'p')
		ft_putptr(va_arg(ptr, void *)); */
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ptr, int));
	if (c == 'u')
		ft_putnbr(va_arg(ptr, unsigned int));
	if (c == 'x')
		ft_putnbr_base(va_arg(ptr, int), "0123456789abcdef");
	if (c == 'X')
		ft_putnbr_base(va_arg(ptr, int), "0123456789ABCDEF");
	if (c == '%')
		ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;

	va_start(ptr, str);
	string_analyse(str, ptr);
	va_end(ptr);
	//return ();
}