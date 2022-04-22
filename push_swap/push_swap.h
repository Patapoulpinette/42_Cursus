/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:03:04 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/22 00:18:39 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>//pour dprintf
# include <limits.h>//pour INT_MAX && INT_MIN
# include <stdlib.h>//pour malloc
# include <stdbool.h>//pour type bool

typedef struct	s_data_stack
{
    int	*stack_a;
    int	*stack_b;
    int	size_a;
    int	size_b;
}				t_data_stack;

//operations
void	swap_a(t_data_stack *stacks);
void	swap_b(t_data_stack *stacks);
void	swap_ab(t_data_stack *stacks);
void	push_a(t_data_stack *stacks);
void	push_b(t_data_stack *stacks);
void	rotate_a(t_data_stack *stacks);
void	rotate_b(t_data_stack *stacks);
void	rotate_ab(t_data_stack *stacks);
void	reverse_rotate_a(t_data_stack *stacks);
void	reverse_rotate_b(t_data_stack *stacks);
void	reverse_rotate_ab(t_data_stack *stacks);

//utils
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);

//algorithm
void	ft_algo_of_fire(t_data_stack *stacks);
int		*indexing(t_data_stack *stacks);
bool	is_sorted(t_data_stack *stacks);

#endif
