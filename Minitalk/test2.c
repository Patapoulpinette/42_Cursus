
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

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
		nb += (str[i] - 48) * ft_recursive_power(2, (len - 1));
		i++;
		len--;
	}
	return (nb);
}

int	main(void)
{
	int	n = 0;

	n = ft_binary_to_dec("010000");
	printf("%d\n", n);
	return (0);
}
