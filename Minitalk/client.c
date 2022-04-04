/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:15:43 by dbouron           #+#    #+#             */
/*   Updated: 2022/04/04 10:21:19 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_dec_to_binary(unsigned int n)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * 8);
	if (!tab)
		return (NULL);
	while (n > 0)
	{
		tab[i] = '0' + n % 2;
		n = n / 2;
		i++;
	}
	while (i < 7)
		tab[i++] = '0';
	tab[i] = '\0';
	ft_strswap(tab);
	return (tab);
}

void	end_of_msg(char *pid)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		kill(ft_atoi(pid), SIGUSR2);
		usleep(100);
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
			usleep(100);
			j++;
		}
		i++;
		j = 0;
		free(str_b);
	}
	end_of_msg(pid);
}

int	analyse_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isascii(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (!*argv[1])
			return (ft_printf("Wrong PID\n"));
		else if (ft_strlen(argv[2]) > 20000)
			return (ft_printf("String too long\n"));
		else if (!analyse_string(argv[2]))
			return (ft_printf("String error : ascii caracteres only\n"));
		else
			ft_atob(argv[2], argv[1]);
		return (0);
	}
	return (ft_printf("Wrong number of arguments\n"));
}
