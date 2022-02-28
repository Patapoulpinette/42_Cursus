/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:15:53 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/28 15:22:35 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>/* pour malloc et free */
# include <unistd.h>/* pour write */
# include <stdarg.h>/* pour va_start, va_arg, va_copy et va_end */

int	ft_printf(const char *str, ...);

#endif