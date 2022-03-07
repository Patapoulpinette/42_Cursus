#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int		i;
	int		j;

	i = ft_printf("1. Je suis une patapoulpinette\n");
	j = printf("1. Je suis une patapoulpinette\n");
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);

	i = ft_printf("2. %d\n", 10);
	j = printf("2. %d\n", 10);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);
	
	i = ft_printf("2. %d est un nombre décimal (base 10) avec d\n", 100);
	j = printf("2. %d est un nombre décimal (base 10) avec d\n", 100);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);

	i = ft_printf("2. %d et %d sont des nombres décimaux (base 10) avec d\n", 101, -10);
	j = printf("2. %d et %d sont des nombres décimaux (base 10) avec d\n", 101, -10);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);
	
	i = ft_printf("2. %d\n", -100);
	j = printf("2. %d\n", -100);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);
	
	i = ft_printf("2. %d\n", -101);
	j = printf("2. %d\n", -101);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);
	
	i = ft_printf("3. %i\n", 10);
	j = printf("3. %i\n", 10);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);
	
	i = ft_printf("3. %i est un nombre décimal (base 10) avec d\n", 100);
	j = printf("3. %i est un nombre décimal (base 10) avec d\n", 100);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);

	i = ft_printf("3. %i et %i sont des nombres décimaux (base 10) avec d\n", 101, -10);
	j = printf("3. %i et %i sont des nombres décimaux (base 10) avec d\n", 101, -10);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);
	
	i = ft_printf("3. %i\n", -100);
	j = printf("3. %i\n", -100);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);
	
	i = ft_printf("3. %i\n", -101);
	j = printf("3. %i\n", -101);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);
	
	j = printf("4. %s\n", NULL);
	printf("--> printf return : %d\n", j);
	i = ft_printf("4. %s\n", NULL);
	printf("--> ft_printf return : %d\n", i);

	i = ft_printf("5. J'affiche un seul caractère : %c\n", 's');
	j = printf("5. J'affiche un seul caractère : %c\n", 's');
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);

	i = ft_printf("6. J'ai mangé %u M&M's\n", 5);
	j = printf("6. J'ai mangé %u M&M's\n", 5);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);

	i = ft_printf("6. J'ai mangé %u M&M's\n", -5);
	j = printf("6. J'ai mangé %u M&M's\n", -5);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);

	i = ft_printf("7. Voici un nombre hexadécimal en minuscule : %x\n", 45864368436488955);
	j = printf("7. Voici un nombre hexadécimal en minuscule : %x\n", 45864368436488955);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);

	i = ft_printf("8. Voici un nombre hexadécimal en majuscule : %X\n", 4556924);
	j = printf("8. Voici un nombre hexadécimal en majuscule : %X\n", 4556924);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);

	i = ft_printf("9. Ma capacité à réfléchir est actuellement de 1%%\n");
	j = printf("9. Ma capacité à réfléchir est actuellement de 1%%\n");
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);

	i = ft_printf("10. Ma capacité à réfléchir est actuellement de %bonjour\n");
	j = printf("10. Ma capacité à réfléchir est actuellement de %bonjour\n");
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);

 	i = ft_printf("10. Ma capacité à réfléchir est actuellement de 1%\n");
	j = printf("10. Ma capacité à réfléchir est actuellement de 1%\n");
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);

 	i = ft_printf("11. Voici le retour d'un pointeur : %p et %p et %p\n", -12, 45, 68464864);
	j = printf("11. Voici le retour d'un pointeur : %p et %p et %p\n", -12, 45, 68464864);
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);

 	i = ft_printf("");
	j = printf("");
	printf("--> ft_printf return : %d\n", i);
	printf("--> printf return : %d\n", j);
	return (0);
}
