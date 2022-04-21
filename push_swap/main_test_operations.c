/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:09:39 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/21 21:53:19 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
int	main(void)
{
	int	i = 0;
	int	a[15] = "123456789";
	int	b[5] = "023";

	//swap & push
	swap_stack(a, b);
	dprintf(2, "a : %s\nb : %s\n", a, b);
	push_a(a, b);
	dprintf(2, "a : %s\nb : %s\n", a, b);
	swap_stack(a, b);
	dprintf(2, "a : %s\nb : %s\n", a, b);
	push_a(a, b);
	dprintf(2, "a : %s\nb : %s\n", a, b);
	
	//rotate
	dprintf(2, "a : %s\nb : %s\n", a, b);
	rotate_ab(a, b);
	dprintf(2, "a : %s\nb : %s\n", a, b);
	
	//reverse rotate
	dprintf(2, "a : %s\nb : %s\n", a, b);
	reverse_rotate_ab(a, b);
	dprintf(2, "a : %s\nb : %s\n", a, b);
	return (0);
} */

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	t_data_stack	stacks;
	
	//initialisation
	i = 1;
	j = 0;
	stacks.size_a = argc - 1;
	stacks.size_b = 0;
	stacks.stack_a = malloc(sizeof(int *) * stacks.size_a);
	stacks.stack_b = malloc(sizeof(int *) * stacks.size_a);
	if (!stacks.stack_a || !stacks.stack_b)
		return (0);
	//remplissage stack A
	while (argv[i] && i < argc)
		stacks.stack_a[j++] = ft_atoi(argv[i++]);
	//opérations
	j = 0;
	dprintf(2, "1---------------init\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille = %d\n", stacks.size_a);
	swap_ab(stacks);
	j = 0;
	dprintf(2, "2---------------swap_ab\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille = %d\n", stacks.size_a);
	push_a(stacks);
	j = 0;
	dprintf(2, "3---------------push_a\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille = %d\n", stacks.size_a);
	swap_ab(stacks);
	j = 0;
	dprintf(2, "4---------------swap_ab\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille = %d\n", stacks.size_a);
	push_b(stacks);
	j = 0;
	dprintf(2, "5---------------push_b\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille = %d\n", stacks.size_a);
	//free
	free(stacks.stack_a);
	free(stacks.stack_b);
	return (0);
}
