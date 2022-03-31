
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

void	ft_invert2(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (str[len] == '0' && len >= 0)
		str[len--] = '1';
	str[len] = '0';
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
		ft_invert2(str);
	}
	while (str[i])
	{
		nb += (str[i] - 48) * ft_recursive_power(2, (len));
		i++;
		len--;
	}
	return (nb * sign);
}

int	main(void)
{
	int	n = 0;

	n = ft_binary_to_dec("1111110111001000");
	printf("%d\n", n);
	return (0);
}
