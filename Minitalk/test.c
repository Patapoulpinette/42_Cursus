
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
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

char	*dec_to_binary(unsigned int n)
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

int main()
{
	char	*tab;
	
	tab = dec_to_binary(16164654);
	printf("%s\n", tab);
	return 0;
}
