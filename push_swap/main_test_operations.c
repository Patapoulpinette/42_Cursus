/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:09:39 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/13 11:13:16 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	char	a[15] = "123456789";
	char	b[5] = "023";

	//swap & push
	dprintf(2, "a : %s\nb : %s\n", a, b);
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
}
