/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:17:36 by dbouron           #+#    #+#             */
/*   Updated: 2022/03/29 16:42:00 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_binary_to_dec(char *str)
{
	int	nb;
	int	i;
	int	len;

	i = 0;
	nb = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		nb += (str[i] - 48) * ft_recursive_power(2, (len -1));
		i++;
		len--;
	}
	return (nb);
}

void	handler(int sigtype)
{
	static int	i = 0;
	static char	binary[17];
	char		letter;
	static char	*result = NULL;

	if (sigtype == SIGUSR1)
		binary[i++] = '1';
	else if (sigtype == SIGUSR2)
			binary[i++] = '0';
	if (i == 16)
	{
		letter = ft_binary_to_dec(binary);
		//dprintf(2, "%s\n", binary);
		result = ft_strcjoin(result, letter);
		if (letter == '\0')
		{
			ft_printf("%s", result);
			free(result);
			result = NULL;
			i = 0;
			return ;
		}
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
