/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:29:50 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/05 10:34:24 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

void	ft_atob(char *str, char *pid);
int		ft_atoi(const char *str);
void	ft_strswap(char *str);
char	*ft_strcjoin(char *s1, char c);
int		ft_recursive_power(int nb, int power);
void	ft_invert_binary_to_negbinary(char *str);
void	ft_invert_negbinary_to_binary(char *str);

#endif