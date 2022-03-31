/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:15:43 by dbouron           #+#    #+#             */
/*   Updated: 2022/03/31 11:29:49 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*dec_to_binary(int n)
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
		ft_invert(tab);
	return (tab);
}

void	end_of_msg(char *pid)
{
	int	i;

	i = 0;
	while (i < 16)
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
		//char *s="❤";
		//dprintf(2, "code ascii lettre : %d\t|\t%c\n", s[0], 231);
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

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (!*argv[1])
			ft_printf("Wrong PID\n");
		else if (ft_strlen(argv[2]) > 20000)
			ft_printf("String too long\n");
		else
			ft_atob(argv[2], argv[1]);
		return (0);
	}
	return (ft_printf("Wrong number of arguments\n"));
}
