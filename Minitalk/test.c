
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strswap(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (str && str[i] && i <= j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

void	ft_invert(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			str[i] = '1';
		else if (str[i] == '1')
			str[i] = '0';
		i++;
	}
	i = ft_strlen(str) - 1;
	if (str[i] == '0')
		str[i] = '1';
	else if (str[i] == '1')
	{
		while (str[i] == '1')
			str[i--] = '0';
		str[i] = '1';
	}
}

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

int	main(void)
{
	char	*tab;

	tab = dec_to_binary(-61);
	printf("%s\n", tab);
	free(tab);
	return (0);
}
