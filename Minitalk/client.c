/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:15:43 by dbouron           #+#    #+#             */
/*   Updated: 2022/03/21 18:45:19 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_atob(char *str, char *pid)
{
	int				i;
	int				j;
	unsigned int	num_b;
	char			*str_b;

	i = 0;
	j = 0;
	if (!str)
		return ;
	if (!pid)
		return ;
	while (str && str[i])
	{
		num_b = ft_putnbr_base(str[i], "01");
		str_b = ft_atoi(num_b);
		while (str_b && str_b[j])
		{
			if (str_b[i] == '1')
				kill(ft_atoi(pid), SIGUSR1);
			else if (str_b[i] == '0')
				kill(ft_atoi(pid), SIGUSR2);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_atob(argv[2], argv[1]);
		return (0);
	}
	return (ft_printf("Wrong number of arguments\n"));
}

/* Ne pas oublier de changer atoi en ft_atoi */

/* int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		kill(atoi(argv[1]), SIGUSR2);
		usleep(15);
		kill(atoi(argv[1]), SIGUSR2);
		usleep(15);
		kill(atoi(argv[1]), SIGUSR2);
		usleep(15);
		kill(atoi(argv[1]), SIGUSR1);
		usleep(15);
		kill(atoi(argv[1]), SIGUSR1);
		usleep(15);
		kill(atoi(argv[1]), SIGUSR2);
		usleep(15);
		kill(atoi(argv[1]), SIGUSR1);
		usleep(15);
		kill(atoi(argv[1]), SIGUSR1);
		usleep(15);
		return (0);
	}
	return (printf("Wrong number of arguments\n"));
} */