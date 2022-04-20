/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:03:04 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/19 12:02:44 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>//pour dprintf
# include <limits.h>//pour INT_MAX

//operations
void	swap_a(char *str);
void	swap_b(char *str);
void	swap_stack(char *str_a, char *str_b);
void	push_a(char *str_a, char *str_b);
void	push_b(char *str_a, char *str_b);
void	rotate_a(char *str);
void	rotate_b(char *str);
void	rotate_ab(char *str_a, char *str_b);
void	reverse_rotate_a(char *str);
void	reverse_rotate_b(char *str);
void	reverse_rotate_ab(char *str_a, char *str_b);

//utils
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);

#endif
