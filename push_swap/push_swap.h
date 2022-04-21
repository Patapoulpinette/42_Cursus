/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:03:04 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/21 18:24:48 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>//pour dprintf
# include <limits.h>//pour INT_MAX && INT_MIN
# include <stdlib.h>//pour malloc
# include <stdbool.h>//pour type bool

//operations
void	swap_a(int *stack_a, int size_a);
void	swap_b(int *stack_b, int size_b);
void	swap_ab(int *stack_a, int *stack_b, int size_a, int size_b);
void	push_a(int *stack_a, int *stack_b, int size_a, int size_b);
void	push_b(int *stack_a, int *stack_b, int size_a, int size_b);
void	rotate_a(int *stack_a, int size_a);
void	rotate_b(int *stack_b, int size_b);
void	rotate_ab(int *stack_a, int *stack_b, int size_a, int size_b);
void	reverse_rotate_a(int *stack_a, int size_a);
void	reverse_rotate_b(int *stack_b, int size_b);
void	reverse_rotate_ab(int *stack_a, int *stack_b, int size_a, int size_b);

//utils
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);

//algorithm
void	ft_algo_of_fire(int *stack_a, int *stack_b, int size);
int		*indexing(int *tab, int size);

#endif
