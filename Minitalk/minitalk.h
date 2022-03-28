/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:29:50 by dbouron           #+#    #+#             */
/*   Updated: 2022/03/28 15:32:36 by dbouron          ###   ########lyon.fr   */
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
int				ft_atoi(const char *str);
char			*ft_dec_to_binary(unsigned int n);
void			ft_strswap(char *str);
char			*ft_strcjoin(char *s1, char c);
int				ft_recursive_power(int nb, int power);

#endif