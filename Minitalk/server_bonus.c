/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:17:36 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/04 17:06:45 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_invert_negbinary_to_binary(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str) - 1;
	if (str[j] == '0')
	{
		while (str[j] == '0' && j > 0)
			str[j--] = '1';
	}
	str[j] = '0';
	while (str[i])
	{
		if (str[i] == '0')
			str[i] = '1';
		else if (str[i] == '1')
			str[i] = '0';
		i++;
	}
}

int	ft_binary_to_dec(char *str)
{
	int	nb;
	int	i;
	int	len;
	int	sign;

	i = 0;
	nb = 0;
	len = ft_strlen(str) - 1;
	sign = 1;
	if (str[i] == '1')
	{
		sign = sign * -1;
		ft_invert_negbinary_to_binary(str);
	}
	while (str[i])
	{
		nb += (str[i] - 48) * ft_recursive_power(2, (len));
		i++;
		len--;
	}
	return (nb * sign);
}

void	confirm_msg(siginfo_t *info)
{
	usleep(300);
	kill(info->si_pid, SIGUSR1);
}

static void	handler(int sigtype, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	binary[17];
	char		letter;
	static char	*result = NULL;

	context = NULL;
	if (sigtype == SIGUSR1)
		binary[i++] = '1';
	else if (sigtype == SIGUSR2)
			binary[i++] = '0';
	if (i == 16)
	{
		letter = ft_binary_to_dec(binary);
		result = ft_strcjoin(result, letter);
		if (letter == '\0')
		{
			ft_printf("%s", result);
			free(result);
			result = NULL;
			i = 0;
			confirm_msg(info);
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
	action.sa_sigaction = &handler;
	action.sa_flags = SA_RESTART;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		sleep (100);
	return (0);
}
