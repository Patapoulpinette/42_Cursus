/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:15:43 by dbouron           #+#    #+#             */
/*   Updated: 2022/03/25 15:22:02 by dbouron          ###   ########lyon.fr   */
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
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) > 20000)
			ft_printf("String too long\n");
		else
			ft_atob(argv[2], argv[1]);
		return (0);
	}
	return (ft_printf("Wrong number of arguments\n"));
}
