/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:09:39 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/22 00:12:53 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

//opérations push & swap
	i = 0;
	j = 0;
	dprintf(2, "init---------------\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille a = %d\n", stacks.size_a);
	while (i < stacks.size_b)
		dprintf(2, "\t%d\n", stacks.stack_b[i++]);
	dprintf(2, "taille b = %d\n", stacks.size_b);
	
	push_b(&stacks);
	i = 0;
	j = 0;
	dprintf(2, "push_b---------------\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille a = %d\n", stacks.size_a);
	while (i < stacks.size_b)
		dprintf(2, "\t%d\n", stacks.stack_b[i++]);
	dprintf(2, "taille b = %d\n", stacks.size_b);
	
	push_b(&stacks);
	i = 0;
	j = 0;
	dprintf(2, "push_b---------------\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille a = %d\n", stacks.size_a);
	while (i < stacks.size_b)
		dprintf(2, "\t%d\n", stacks.stack_b[i++]);
	dprintf(2, "taille b = %d\n", stacks.size_b);
	
	swap_ab(&stacks);
	i = 0;
	j = 0;
	dprintf(2, "swap_ab---------------\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille a = %d\n", stacks.size_a);
	while (i < stacks.size_b)
		dprintf(2, "\t%d\n", stacks.stack_b[i++]);
	dprintf(2, "taille b = %d\n", stacks.size_b);
	
	push_a(&stacks);
	i = 0;
	j = 0;
	dprintf(2, "push_a---------------\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille a = %d\n", stacks.size_a);
	while (i < stacks.size_b)
		dprintf(2, "\t%d\n", stacks.stack_b[i++]);
	dprintf(2, "taille b = %d\n", stacks.size_b);
	
	swap_ab(&stacks);
	i = 0;
	j = 0;
	dprintf(2, "swap_ab---------------\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille a = %d\n", stacks.size_a);
	while (i < stacks.size_b)
		dprintf(2, "\t%d\n", stacks.stack_b[i++]);
	dprintf(2, "taille b = %d\n", stacks.size_b);
	
	push_b(&stacks);
	i = 0;
	j = 0;
	dprintf(2, "push_b---------------\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille a = %d\n", stacks.size_a);
	while (i < stacks.size_b)
		dprintf(2, "\t%d\n", stacks.stack_b[i++]);
	dprintf(2, "taille b = %d\n", stacks.size_b);

	push_b(&stacks);
	i = 0;
	j = 0;
	dprintf(2, "push_b---------------\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille a = %d\n", stacks.size_a);
	while (i < stacks.size_b)
		dprintf(2, "\t%d\n", stacks.stack_b[i++]);
	dprintf(2, "taille b = %d\n", stacks.size_b);

//opérations rotate
	rotate_ab(&stacks);
	i = 0;
	j = 0;
	dprintf(2, "rotate_ab---------------\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille a = %d\n", stacks.size_a);
	while (i < stacks.size_b)
		dprintf(2, "\t%d\n", stacks.stack_b[i++]);
	dprintf(2, "taille b = %d\n", stacks.size_b);
	
//opérations reverse rotate	
	reverse_rotate_ab(&stacks);
	i = 0;
	j = 0;
	dprintf(2, "reverse_rotate_ab---------------\n");
	while (j < stacks.size_a)
		dprintf(2, "\t%d\n", stacks.stack_a[j++]);
	dprintf(2, "taille a = %d\n", stacks.size_a);
	while (i < stacks.size_b)
		dprintf(2, "\t%d\n", stacks.stack_b[i++]);
	dprintf(2, "taille b = %d\n", stacks.size_b);

	//free
	free(stacks.stack_a);
	free(stacks.stack_b);
	return (0);
}
