/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:29:50 by dbouron           #+#    #+#             */
/*   Updated: 2022/03/22 10:56:51 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"

void			handler(int sigtype);
void			ft_atob(char *str, char *pid);
unsigned int	ft_putnbr_base(unsigned int nbr, char *base);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);

#endif