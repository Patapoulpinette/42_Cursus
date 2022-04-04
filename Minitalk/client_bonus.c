/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:15:43 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/04 11:40:57 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*ft_dec_to_binary(int n)
{
	char	*tab;
	int		i;
	int		nb;

	i = 0;
	nb = n;
	if (n < 0)
		nb = nb * -1;
	tab = malloc(sizeof(char) * 17);
	if (!tab)
		return (NULL);
	while (nb > 0)
	{
		tab[i] = '0' + nb % 2;
		nb = nb / 2;
		i++;
	}
	while (i < 16)
		tab[i++] = '0';
	tab[i] = '\0';
	ft_strswap(tab);
	if (n < 0)
		ft_invert_binary_to_negbinary(tab);
	return (tab);
}

void	end_of_msg(char *pid)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		kill(ft_atoi(pid), SIGUSR2);
		usleep(200);
		i++;
	}
}

void	ft_atob(char *str, char *pid)
{
	int				i;
	int				j;
	char			*str_b;

	i = 0;
	j = 0;
	if (!str || !pid)
		return ;
	while (str[i])
	{
		str_b = ft_dec_to_binary(str[i]);
		while (str_b && str_b[j])
		{
			if (str_b[j] == '1')
				kill(ft_atoi(pid), SIGUSR1);
			else if (str_b[j] == '0')
				kill(ft_atoi(pid), SIGUSR2);
			usleep(200);
			j++;
		}
		i++;
		j = 0;
		free(str_b);
	}
	end_of_msg(pid);
}

static void	handler_client(int sigtype)
{
	if (sigtype == SIGUSR1)
		ft_printf("Message received\n");
	return ;
}

int	main(int argc, char **argv)
{
	struct sigaction	action_client;

	if (argc == 3)
	{
		if (!*argv[1])
			return (ft_printf("Wrong PID\n"));
		else if (ft_strlen(argv[2]) > 20000)
			return (ft_printf("String too long\n"));
		else
			ft_atob(argv[2], argv[1]);
		action_client.sa_handler = handler_client;
		sigaction(SIGUSR1, &action_client, NULL);
		pause();
		return (0);
	}
	return (ft_printf("Wrong number of arguments\n"));
}
