/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:15:43 by dbouron           #+#    #+#             */
/*   Updated: 2022/03/24 12:09:57 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_dec_to_binary(unsigned int n)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * 33);
	if (!tab)
		return (NULL);
	while (n > 0)
	{
		tab[i] = '0' + n % 2;
		n = n / 2;
		i++;
	}
	tab[i] = '\0';
	ft_strswap(tab);
	return (tab);
}

void	ft_atob(char *str, char *pid)
{
	int				i;
	int				j;
	char			*str_b;

	i = 0;
	j = 0;
	if (!str)
		return ;
	if (!pid)
		return ;
	puts("2");
	while (str && str[i])
	{
		puts("3");
		str_b = ft_dec_to_binary(str[i]);
		puts(str_b);
		while (str_b && str_b[j])
		{
			printf("Character : %c\n", str_b[j]);
			if (str_b[j] == '1')
				kill(ft_atoi(pid), SIGUSR1);
			else if (str_b[j] == '0')
				kill(ft_atoi(pid), SIGUSR2);
			usleep(15);
			j++;
		}
		i++;
		j = 0;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		puts("1");
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