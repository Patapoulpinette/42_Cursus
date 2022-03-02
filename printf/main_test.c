#include "ft_printf.h"

int main(void)
{
	int		i;
	int		j;
	void	*p;

	i = ft_printf("1. Je suis une patapoulpinette\n");
	j = printf("1. Je suis une patapoulpinette\n");
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);

	i = ft_printf("%d\n", -1560000);
	j = printf("%d\n", -1560000);
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);
	
	i = ft_printf("2. %d est un nombre décimal (base 10) avec d\n", -1560000);
	j = printf("2. %d est un nombre décimal (base 10) avec d\n", -1560000);
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);

	i = ft_printf("2. %d et %d sont des nombres décimaux (base 10) avec d\n", 1560000, 568484);
	j = printf("2. %d et %d sont des nombres décimaux (base 10) avec d\n", 1560000, 568484);
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);
	
	i = ft_printf("3. %i est un nombre entier avec i\n", "fd441865");
	j = printf("3. %i est un nombre entier avec i\n", "fd441865");
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);

	i = ft_printf("3. %i est un nombre entier (base 10) avec i\n", 12);
	j = printf("3. %i est un nombre entier (base 10) avec i\n", 12);
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);

	i = ft_printf("4. La chaine de caractères retournée est : %s\n", "Je suis une patapoulpinette");
	j = printf("4. La chaine de caractères retournée est : %s\n", "Je suis une patapoulpinette");
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);

	i = ft_printf("4. Les chaines de caractères retournées sont : \"%s\" et \"%s\"\n", "Je suis une patapoulpinette", "Et alors ?");
	j = printf("4. Les chaines de caractères retournées sont : \"%s\" et \"%s\"\n", "Je suis une patapoulpinette", "Et alors ?");
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);
	
	i = ft_printf("5. J'affiche un seul caractère : %c\n", 's');
	j = printf("5. J'affiche un seul caractère : %c\n", 's');
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);

	i = ft_printf("6. J'ai mangé %u M&M's\n", 5);
	j = printf("6. J'ai mangé %u M&M's\n", 5);
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);

	i = ft_printf("6. J'ai mangé %u M&M's\n", -5);
	j = printf("6. J'ai mangé %u M&M's\n", -5);
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);

	i = ft_printf("7. Voici un nombre hexadécimal en minuscule : %x\n", -45868955);
	j = printf("7. Voici un nombre hexadécimal en minuscule : %x\n", -45868955);
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);

	i = ft_printf("8. Voici un nombre hexadécimal en majuscule : %X\n", 4556);
	j = printf("8. Voici un nombre hexadécimal en majuscule : %X\n", 4556);
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);

	i = ft_printf("9. Ma capacité à réfléchir est actuellement de 1%%\n");
	j = printf("9. Ma capacité à réfléchir est actuellement de 1%%\n");
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);

	i = ft_printf("10. Ma capacité à réfléchir est actuellement de %bonjour\n");
	j = printf("10. Ma capacité à réfléchir est actuellement de %bonjour\n");
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);

	i = ft_printf("10. Ma capacité à réfléchir est actuellement de 1%\n");
	j = printf("10. Ma capacité à réfléchir est actuellement de 1%\n");
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);

	i = ft_printf("11. Voici le retour d'un pointeur : %p\n", p);
	j = printf("11. Voici le retour d'un pointeur : %p\n", p);
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);

	i = ft_printf("");
	j = printf("");
	printf("ft_printf return : %d\n", i);
	printf("printf return : %d\n", j);
	return (0);
}
