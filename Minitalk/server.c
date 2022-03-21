/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:17:36 by dbouron           #+#    #+#             */
/*   Updated: 2022/03/21 18:45:06 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sigtype)
{
	static int	i = 0;
	static char	binary[9];

	if (sigtype == SIGUSR1)
		binary[i++] = '1';
	else if (sigtype == SIGUSR2)
		binary[i++] = '0';
	if (i == 8)
	{
		ft_printf("string reçue : %s\n", binary);
		i = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	printf("PID : %d\n", pid);
	action.sa_handler = handler;
	action.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		sleep (100);
	return (0);
}

/* Ne pas oublier de changer printf en ft_printf */