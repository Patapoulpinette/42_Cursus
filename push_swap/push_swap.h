/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:03:04 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/28 11:33:55 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>//for INT_MAX && INT_MIN
# include <stdlib.h>//for malloc
# include <stdbool.h>//for type bool
# include <unistd.h>//for write

typedef struct s_data_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}				t_data_stack;

//main
void	initializing(int argc, t_data_stack *stacks);
void	free_to_quit(t_data_stack *stacks);

//parsing
int		parsing(int argc, char **argv);
int		parsing_digit(int argc, char **tab);
int		parsing_int(int argc, char **tab);
void	check_0_before_nb(char *str);
int		parsing_duplicates(int argc, char **tab);

//operations
void	swap_a(t_data_stack *stacks, int mode);
void	swap_b(t_data_stack *stacks, int mode);
void	swap_ab(t_data_stack *stacks);
void	push_a(t_data_stack *stacks);
void	push_b(t_data_stack *stacks);
void	rotate_a(t_data_stack *stacks, int mode);
void	rotate_b(t_data_stack *stacks, int mode);
void	rotate_ab(t_data_stack *stacks);
void	reverse_rotate_a(t_data_stack *stacks, int mode);
void	reverse_rotate_b(t_data_stack *stacks, int mode);
void	reverse_rotate_ab(t_data_stack *stacks);

//utils
int		ft_strlen(char const *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
bool	is_sorted(t_data_stack *stacks);

//algorithm
int		*indexing(t_data_stack *stacks);
int		search_smaller_nbr(t_data_stack *stacks);
void	sorting_3nbrs(t_data_stack *stacks);
void	sorting_5nbrs(t_data_stack *stacks);
void	sorting_radix(t_data_stack *stacks);

#endif
